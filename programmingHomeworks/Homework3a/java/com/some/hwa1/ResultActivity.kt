package com.some.hwa1

import android.app.Activity
import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.TextView
import android.widget.Toast

class ResultActivity : AppCompatActivity() {
    private lateinit var text: TextView

    internal companion object {
        @JvmStatic
        internal lateinit var savedSelected: String
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_result)
        text = findViewById(R.id.textView)
        text.text = intent.getStringExtra("weather")
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menu!!.add("Send to")
        return super.onCreateOptionsMenu(menu)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        if (item.itemId == android.R.id.home) MainActivity.returnValue = "some"

        when (item.title) { "Send to" -> share() }
        return super.onOptionsItemSelected(item)
    }

    private fun share() {
        startActivity(Intent.createChooser(Intent(Intent.ACTION_SEND).setType("text/plain").putExtra(Intent.EXTRA_TEXT, text.text),
                "Chose application"))
    }
}
