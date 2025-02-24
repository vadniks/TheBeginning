package com.some.hwa1

import android.content.Context
import android.content.SharedPreferences
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.v7.widget.DividerItemDecoration
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.*

/**
 * @author Vad Nik.
 * @version dated June 08, 2018.
 * @link https://github.com/vadniks
 */

/*
I made recyclerView in activity and weather description in fragment.
Thing it'll do for first task.
 */

class MainActivity : AppCompatActivity() {
    private lateinit var sh: SharedPreferences
    private lateinit var rv: RecyclerView

    private companion object {
        @JvmStatic
        private val items: ArrayList<String> = ArrayList()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        init()
    }

    private inner class Adapter(private val arr: ArrayList<String>, private val block: MainActivity) :
            RecyclerView.Adapter<MainActivity.Adapter.ViewHolder>() {

        override fun onCreateViewHolder(p0: ViewGroup, p1: Int): ViewHolder {
            val view: View = LayoutInflater.from(p0.context).inflate(R.layout.item_rec_view, p0, false)
            val viewHolder = ViewHolder(view)
            viewHolder.itemView.setOnClickListener { _ -> block.onClick(viewHolder.adapterPosition) }
            return viewHolder
        }

        override fun getItemCount() = items.size

        override fun onBindViewHolder(p0: ViewHolder, p1: Int) {
            p0.text.text = arr[p1]
        }

        inner class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
            var text: TextView = itemView.findViewById(R.id.itemText)
        }
    }

    private fun init() {
        sh = getPreferences(Context.MODE_PRIVATE)

        if (items.size == 0)
            items.addAll(resources.getStringArray(R.array.cities))

        rv = findViewById(R.id.recV)
        rv.setHasFixedSize(true)
        rv.layoutManager = LinearLayoutManager(this)
        rv.adapter = Adapter(items, this)
        rv.addItemDecoration(DividerItemDecoration(this, LinearLayoutManager.VERTICAL))
    }

    private fun onClick(id: Int) {
        val arr = this.resources.getStringArray(R.array.weather)

        if (supportFragmentManager.backStackEntryCount > 0)
            supportFragmentManager
                    .beginTransaction()
                    .replace(R.id.actMain, FragmentResult.newInstance(arr[id], id, this))
                    .addToBackStack(null)
                    .commit()
        else
            supportFragmentManager
                    .beginTransaction()
                    .add(R.id.actMain, FragmentResult.newInstance(arr[id], id, this))
                    .addToBackStack(null)
                    .commit()

        supportFragmentManager.executePendingTransactions()
    }
}
