package com.some.hwa1

import android.app.Activity
import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.*

/**
 * @author Vad Nik.
 * @version dated June 01, 2018.
 * @link https://github.com/vadniks
 */
private const val TAG: String = "LifecycleTest"

class MainActivity : AppCompatActivity() {
    private lateinit var sh: SharedPreferences
    private lateinit var selected: String
    private lateinit var spin: Spinner
    private var showPres: Boolean = false
    private var showForTom: Boolean = false
    private var showForNWeek: Boolean = false

    internal companion object {
        @JvmStatic
        internal val RESULT: String = "result"
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        init()

        for ((i, o: String) in resources.getStringArray(R.array.cities).withIndex()) {
            if (o == selected)
                spin.setSelection(i)
        }

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

    override fun onStart() {
        super.onStart()
        Log.i(TAG, "onStart")
    }

    override fun onResume() {
        super.onResume()
        Log.i(TAG, "onResume")
    }

    override fun onSaveInstanceState(outState: Bundle) {
        outState.putString("selected", selected)
        super.onSaveInstanceState(outState)
    }

    private fun init() {
        sh = getPreferences(Context.MODE_PRIVATE)

        spin = findViewById(R.id.spinner)

        for ((i, o: String) in resources.getStringArray(R.array.cities).withIndex()) {
            if (o == loadSelected())
                spin.setSelection(i)
        }

        selected = spin.selectedItem.toString()

        spin.onItemSelectedListener = object : AdapterView.OnItemSelectedListener {
            override fun onNothingSelected(parent: AdapterView<*>?) {}

            override fun onItemSelected(parent: AdapterView<*>?, view: View?, position: Int, id: Long) {
                saveSelected(spin.selectedItem.toString())
            }
        }

        val bt = findViewById<Button>(R.id.button)
        bt.setOnClickListener { onButtonClick(spin) }
    }

    private fun onButtonClick(spin: Spinner) {
        val arr = this.resources.getStringArray(R.array.weather)

        startActivityForResult(Intent(this@MainActivity, ResultActivity::class.java)
                .putExtra("weather", arr[spin.selectedItemId.toInt()])
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

    private annotation class OnlyCity // Something like @StringDef but I need to define strings in runtime, annotations don't support this.

    private fun saveSelected(@OnlyCity selected: String) {
        val ed: SharedPreferences.Editor = sh.edit()
        ed.putString("selected", selected)
        ed.apply()
    }

    private fun loadSelected() = sh.getString("selected", resources.getStringArray(R.array.cities)[0])

    override fun onPause() {
        super.onPause()
        Log.i(TAG, "onPause")
    }

    override fun onStop() {
        super.onStop()
        Log.i(TAG, "onStop")
    }

    override fun onDestroy() {
        super.onDestroy()
        Log.i(TAG, "onDestroy")
    }
}
