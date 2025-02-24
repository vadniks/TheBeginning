package com.some.hwa1

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView

class PortraitActivity : AppCompatActivity() {
    private var index: Int = 0
    private lateinit var arr: Array<String>
    private var id: Int = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_portrait)

        index = intent.getIntExtra("id", 0)
        arr = intent.getStringArrayExtra("arr")
        id = if (index == 0) R.array.extras else R.array.extras2

        val weather: TextView = findViewById(R.id.textWeather)
        weather.text = arr[index]

        val pr: TextView = findViewById(R.id.textV)
        pr.text = resources.getStringArray(id)[0]

        val tm: TextView = findViewById(R.id.textV2)
        tm.text = resources.getStringArray(id)[1]

        val nw: TextView = findViewById(R.id.textV3)
        nw.text = resources.getStringArray(id)[2]
    }
}
