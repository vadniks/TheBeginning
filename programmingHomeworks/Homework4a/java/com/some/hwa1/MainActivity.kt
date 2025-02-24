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
 * @version dated May 29, 2018.
 * @link https://github.com/vadniks
 */
/*
For task 1 please see ResultActivity.
For task 3 please get a look in manifest.
 */
private const val TAG: String = "LifecycleTest"

class MainActivity : AppCompatActivity() {
    private lateinit var sh: SharedPreferences
    private lateinit var selected: String
    private lateinit var spin: Spinner

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

        Log.i(TAG, "onCreate")
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

//        val j: String = loadSelected()
//        for ((i, o: String) in resources.getStringArray(R.array.cities).withIndex()) {
//            if (o == j)
//                ResultActivity.savedSelected = resources.getStringArray(R.array.weather)[i]
//        }

        val bt = findViewById<Button>(R.id.button)
        bt.setOnClickListener { onButtonClick(spin) }
    }

    private fun onButtonClick(spin: Spinner) {
        val arr = this.resources.getStringArray(R.array.weather)

        startActivityForResult(Intent(this@MainActivity, ResultActivity::class.java).putExtra("weather",
                arr[spin.selectedItemId.toInt()]), 1)
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
