package com.some.hwa1

import android.content.Context
import android.content.SharedPreferences
import android.support.v7.app.AppCompatActivity
import android.support.design.widget.Snackbar
import android.os.Bundle
import android.view.View
import android.widget.AdapterView
import android.widget.Button
import android.widget.Spinner
import android.widget.TextView

/**
 * @author Vad Nik.
 * @version dated May 22, 2018.
 * @link https://github.com/vadniks
 */
class MainActivity : AppCompatActivity() {
    private var text: TextView? = null
    private var sh: SharedPreferences? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        init()
    }

    /*
    How do you like my dark theme?
     */

    private fun init() {
        sh = getPreferences(Context.MODE_PRIVATE)

        val spin = findViewById<Spinner>(R.id.spinner)

        for ((i, o: String) in resources.getStringArray(R.array.cities).withIndex()) {
            if (o == loadSelected())
                spin.setSelection(i)
        }

        spin.onItemSelectedListener = object : AdapterView.OnItemSelectedListener {
            override fun onNothingSelected(parent: AdapterView<*>?) {}

            override fun onItemSelected(parent: AdapterView<*>?, view: View?, position: Int, id: Long) {
                saveSelected(spin.selectedItem.toString())

                val arr = resources.getStringArray(R.array.weather)

                assert(text != null)
                text?.text = arr[spin.selectedItemId.toInt()]
            }
        }

        text = findViewById(R.id.textView)
        assert(text != null)

        val j: String = loadSelected()
        for ((i, o: String) in resources.getStringArray(R.array.cities).withIndex()) {
            if (o == j)
                text?.text = resources.getStringArray(R.array.weather)[i]
        }

        val bt = findViewById<Button>(R.id.button)
        bt.setOnClickListener { v -> onButtonClick(spin, v!!) }
    }

    private fun onButtonClick(spin: Spinner, v: View) {
        Snackbar.make(v, "Button is useless", Snackbar.LENGTH_LONG).show()

        val arr = this.resources.getStringArray(R.array.weather)

        assert(text != null)
        text?.text = arr[spin.selectedItemId.toInt()]
    }

    private annotation class OnlyCity // Can be added @StringDef

    private fun saveSelected(@OnlyCity selected: String) {
        val ed: SharedPreferences.Editor = sh!!.edit()
        ed.putString("selected", selected)
        ed.apply()
    }

    private fun loadSelected() = sh!!.getString("selected", resources.getStringArray(R.array.cities)[0])
}
