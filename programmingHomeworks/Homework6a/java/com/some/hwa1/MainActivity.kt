package com.some.hwa1

import android.app.Activity
import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.v7.widget.DividerItemDecoration
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.*

/**
 * @author Vad Nik.
 * @version dated June 05, 2018.
 * @link https://github.com/vadniks
 */
private const val TAG: String = "LifecycleTest"

class MainActivity : AppCompatActivity() {
    private lateinit var sh: SharedPreferences
    private lateinit var rv: RecyclerView
    private var showPres: Boolean = false
    private var showForTom: Boolean = false
    private var showForNWeek: Boolean = false

    internal companion object {
        @JvmStatic
        internal val RESULT: String = "result"
        @JvmStatic
        private val items: ArrayList<String> = ArrayList()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        init()

        val ch1: CheckBox = findViewById(R.id.checkBox)
        val ch2: CheckBox = findViewById(R.id.checkBox2)
        val ch3: CheckBox = findViewById(R.id.checkBox3)
        initCheckBoxes(ch1, ch2, ch3)

        Log.i(TAG, "onCreate")
    }

    private fun initCheckBoxes(ch1: CheckBox, ch2: CheckBox, ch3: CheckBox) {
        showPres = sh.getBoolean("ch1", false)
        showForTom = sh.getBoolean("ch2", false)
        showForNWeek = sh.getBoolean("ch3", false)

        ch1.isChecked = showPres
        ch2.isChecked = showForTom
        ch3.isChecked = showForNWeek

        ch1.setOnCheckedChangeListener { _, isChecked ->
            showPres = isChecked
            val ed: SharedPreferences.Editor = sh.edit()
            ed.putBoolean("ch1", isChecked)
            ed.apply() }

        ch2.setOnCheckedChangeListener { _, isChecked ->
            showForTom = isChecked
            val ed: SharedPreferences.Editor = sh.edit()
            ed.putBoolean("ch2", isChecked)
            ed.apply() }

        ch3.setOnCheckedChangeListener { _, isChecked ->
            showForNWeek = isChecked
            val ed: SharedPreferences.Editor = sh.edit()
            ed.putBoolean("ch3", isChecked)
            ed.apply() }
    }

    private class Adapter(private val arr: ArrayList<String>, private val block: MainActivity) :
            RecyclerView.Adapter<MainActivity.Adapter.ViewHolder>() {

        override fun onCreateViewHolder(p0: ViewGroup, p1: Int): ViewHolder {
            val view: View = LayoutInflater.from(p0.context).inflate(R.layout.item_rec_view, p0, false)
            val viewHolder = ViewHolder(view)
            viewHolder.itemView.setOnClickListener { _ -> block.onClick(viewHolder.adapterPosition) }
            return viewHolder
        }

        override fun getItemCount(): Int {
            return items.size
        }

        override fun onBindViewHolder(p0: ViewHolder, p1: Int) {
            p0.text.text = arr[p1]
        }

        inner class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
            var text: TextView = itemView.findViewById(R.id.itemText)
        }
    }

    private fun init() {
        sh = getPreferences(Context.MODE_PRIVATE)

        items.addAll(resources.getStringArray(R.array.cities))

        rv = findViewById(R.id.recV)
        rv.setHasFixedSize(true)
        rv.layoutManager = LinearLayoutManager(this)
        rv.adapter = Adapter(items, this)
        rv.addItemDecoration(DividerItemDecoration(this, LinearLayoutManager.VERTICAL))
    }

    private fun onClick(id: Int) {
        val arr = this.resources.getStringArray(R.array.weather)

        startActivityForResult(Intent(this@MainActivity, ResultActivity::class.java)
                .putExtra("weather", arr[id])
                .putExtra("ch1", showPres)
                .putExtra("ch2", showForTom)
                .putExtra("ch3", showForNWeek), 1)
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        if (resultCode == Activity.RESULT_OK)
            Toast.makeText(this@MainActivity, data?.getStringExtra(RESULT), Toast.LENGTH_LONG).show()
        else if (resultCode == Activity.RESULT_CANCELED)
            Toast.makeText(this@MainActivity, data?.getStringExtra(RESULT), Toast.LENGTH_LONG).show()

        super.onActivityResult(requestCode, resultCode, data)
    }
}
