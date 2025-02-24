package com.some.hwa1

import android.app.Activity
import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import android.view.View
import android.widget.TextView
import android.widget.Toast

class ResultActivity : AppCompatActivity() {
    private lateinit var text: TextView
    private var some: Int = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_result)
        text = findViewById(R.id.textView)
        text.text = intent.getStringExtra("weather")
        initTexts()

        if (savedInstanceState != null) {
            Log.d("deb", "restoring...")
            Toast.makeText(this, savedInstanceState.getInt("someV").toString(), Toast.LENGTH_LONG).show() // for task 1
        }

        some++
        setResult(Activity.RESULT_OK, Intent(this@ResultActivity, MainActivity::class.java).putExtra(MainActivity.RESULT,
                "some"))
    }

    private fun initTexts() {
        val t1: TextView = findViewById(R.id.textView2)
        val t2: TextView = findViewById(R.id.textView3)
        val t3: TextView = findViewById(R.id.textView4)

        if (intent.getBooleanExtra("ch1", false))
            t1.text = getString(R.string.pressure)
        else
            t1.visibility = View.INVISIBLE

        if (intent.getBooleanExtra("ch2", false))
            t2.text = getString(R.string.forecastTom)
        else
            t2.visibility = View.INVISIBLE

        if (intent.getBooleanExtra("ch3", false))
            t3.text = getString(R.string.forecastForNWeek)
        else
            t3.visibility = View.INVISIBLE
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menu!!.add("Send to")
        return super.onCreateOptionsMenu(menu)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        if (item.itemId == android.R.id.home) {
            setResult(Activity.RESULT_OK, Intent(this@ResultActivity, MainActivity::class.java).putExtra(MainActivity.RESULT,
                    "some"))
            finish()
            super.onBackPressed()
            return true
        }

        when (item.title) { "Send to" -> share() }
        return super.onOptionsItemSelected(item)
    }

    override fun onSaveInstanceState(outState: Bundle) { // for task 1
        outState.putInt("someV", some)
        Log.d("deb", "saved")
        super.onSaveInstanceState(outState)
    }

    private fun share() {
        startActivity(Intent.createChooser(Intent(Intent.ACTION_SEND).setType("text/plain").putExtra(Intent.EXTRA_TEXT, text.text),
                "Chose application"))
    }
}
