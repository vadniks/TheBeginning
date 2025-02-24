package com.some.hwa1

import android.app.Activity
import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import android.widget.TextView
import android.widget.Toast

class ResultActivity : AppCompatActivity() {
    private lateinit var text: TextView
    private var some: Int = 0 // for task 1

//    internal companion object {
//        @JvmStatic
//        internal lateinit var savedSelected: String
//    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_result)
        text = findViewById(R.id.textView)
        text.text = intent.getStringExtra("weather")

        if (savedInstanceState != null) {
            Log.d("deb", "restoring...")
            Toast.makeText(this, savedInstanceState.getInt("someV").toString(), Toast.LENGTH_LONG).show() // for task 1
        }

        some++
        setResult(Activity.RESULT_OK, Intent(this@ResultActivity, MainActivity::class.java).putExtra(MainActivity.RESULT,
                "some"))
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
