package com.some.hwa1

import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.*

/**
 * @author Vad Nik.
 * @version dated May 25, 2018.
 * @link https://github.com/vadniks
 */
class MainActivity : AppCompatActivity() {
    private lateinit var sh: SharedPreferences

    internal companion object {
        @JvmStatic
        internal var returnValue: String = ""
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        init()
    }

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

                returnValue = spin.selectedItem.toString()

                // I get you why we need to use button. Don't uncomment code below.

//                startActivity(Intent(this@MainActivity, ResultActivity::class.java).putExtra("weather",
//                        arr[spin.selectedItemId.toInt()]))
            }
        }

        val j: String = loadSelected()
        for ((i, o: String) in resources.getStringArray(R.array.cities).withIndex()) {
            if (o == j)
                ResultActivity.savedSelected = resources.getStringArray(R.array.weather)[i]
        }

        val bt = findViewById<Button>(R.id.button)
        bt.setOnClickListener { onButtonClick(spin) }
    }

    override fun onResume() {
        if (returnValue != "")
            Toast.makeText(this@MainActivity, returnValue, Toast.LENGTH_LONG).show()

        super.onResume()
    }

    private fun onButtonClick(spin: Spinner) {
        val arr = this.resources.getStringArray(R.array.weather)

        startActivity(Intent(this@MainActivity, ResultActivity::class.java).putExtra("weather",
                arr[spin.selectedItemId.toInt()])) // why i must use this instead of ::class ? And this@MainActivity instead of this.
    }

    private annotation class OnlyCity // Something like @StringDef but I need to define strings in runtime, annotations don't support this.

    private fun saveSelected(@OnlyCity selected: String) {
        val ed: SharedPreferences.Editor = sh.edit()
        ed.putString("selected", selected)
        ed.apply()
    }

    private fun loadSelected() = sh.getString("selected", resources.getStringArray(R.array.cities)[0])
}
