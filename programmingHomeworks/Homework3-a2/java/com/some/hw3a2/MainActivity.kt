package com.some.hw3a2

import android.annotation.SuppressLint
import android.app.DialogFragment
import android.content.Context
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ArrayAdapter
import android.widget.TextView
import android.widget.Toast

import com.google.gson.JsonObject
import com.google.gson.JsonParser

import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.layout_dialog.view.*

import kotlinx.coroutines.experimental.*
import okhttp3.*

//import java.io.BufferedReader
//import java.io.IOException
//import java.io.InputStreamReader

import java.net.HttpURLConnection
import java.net.URL

import java.util.*

private const val API = ""
private const val OPEN_WEATHER_MAP_API = "http://api.openweathermap.org/data/2.5/weather?q=%s&units=metric"
private const val KEY = "x-api-key"
private const val RESPONSE = "cod"
private const val ALL_GOOD = 200

//There's no final keyword in kotlin, const keyword is used instead but it doesn't applicable to non-primitive types.
//And it's only allowed on top-level and objects (outside classes).
private val CITIES: Array<String> = arrayOf("London", "Paris")

//Target API is 21.

//Star typing first 2 letters of city, like lo - London.

/**
 * @author Vad Nik.
 * @version dated July 7, 2018.
 * @link github.com/vadniks
 */
class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        cityF = city
        detailsF = details

        city.visibility = View.INVISIBLE
        details.visibility = View.INVISIBLE
        button.setOnClickListener { _: View? -> showDialog() }
    }

    private fun showDialog(): Unit = Dialog().show(fragmentManager, "dialogHw3a2")

    class Dialog : DialogFragment() {
        private var selected: String? = null

        override fun onCreateView(inflater: LayoutInflater?, container: ViewGroup?, savedInstanceState: Bundle?): View {
            dialog.setTitle(R.string.choose_city)

            val view: View = inflater?.inflate(R.layout.layout_dialog, container)!!
            view.btDone.setOnClickListener { _: View? -> this done view }
            view.actv.setAdapter(this createAdapter view)
            view.actv.setOnItemClickListener { _, _, _, _ ->
                selected = view.actv.text.toString() }

            return view
        }

        private infix fun done(view: View) {
            selected = view.actv.text.toString()

            if (selected == null || selected == "") {
                Toast.makeText(view.context, getString(R.string.textEmpty), Toast.LENGTH_LONG).show()
                return
            }

            //Kotlin multithreading. DO NOT CHANGE ANYTHING IN THIS BLOCK!
            val obj: JsonObject? = runBlocking { anc(view.context).await() }

            //launch { obj = anc().await() }

            //runBlocking { obj = MainActivity getJSON selected!! }

            if (obj == null) {
                Toast.makeText(view.context, getString(R.string.noPlace), Toast.LENGTH_LONG).show()
                return
            }

            Handler(Looper.getMainLooper()).post { this render obj }
        }

        private fun anc(context: Context) = async(CommonPool) {
            return@async MainActivity.getJSON(selected!!, context)
        }

        @SuppressLint("SetTextI18n")
        private infix fun render(obj: JsonObject) {
            //TODO: view is in layout_dialog not in activity_main

            cityF.text = obj.get("name").asString.toUpperCase(Locale.US)

            val det: JsonObject = obj.get("weather").asJsonArray[0].asJsonObject
            val main: JsonObject = obj.get("main").asJsonObject

            detailsF.text = "${det.get("description").asString.toUpperCase(Locale.US)}\n" +
                    "Humidity: ${main.get("humidity").asString}% \n Pressure: ${main.get("pressure").asString}hPa\n" +
                    "${String.format("%.2f", main.get("temp").asDouble)} ℃"

            cityF.visibility = View.VISIBLE
            detailsF.visibility = View.VISIBLE

            dismiss()
        }

        private infix fun createAdapter(view: View): ArrayAdapter<String> =
                ArrayAdapter(view.context, android.R.layout.simple_dropdown_item_1line, CITIES)
    }

    //Instead of static definition.
    companion object {
        @SuppressLint("StaticFieldLeak")
        private lateinit var cityF: TextView
        @SuppressLint("StaticFieldLeak")
        private lateinit var detailsF: TextView

        private fun getJSON(city: String, context: Context): JsonObject? {
            val url = URL(String.format(OPEN_WEATHER_MAP_API, city))

            println("url ${url.toString()}")

            val b: HttpUrl.Builder = HttpUrl.parse(url.toString()).newBuilder()
            b.addQueryParameter(KEY, API)

            println("u2 ${b.build().uri()}")

            val request: Request = Request.Builder().header(KEY, API).url(url).build()

            var raw = String()

            val client = OkHttpClient()
            raw = client.newCall(request).execute().body().string()/*.enqueue(object : Callback {

                override fun onFailure(call: Call?, e: IOException?) {
                    e?.printStackTrace()
                    call?.cancel()
                    Toast.makeText(context, context.getString(R.string.rFailed), Toast.LENGTH_LONG).show()
                }

                override fun onResponse(call: Call?, response: Response) {

                    println("msg ${response.message()}")

                    raw = response.body().string()
                    response.close()
                }
            })*/

            val con: HttpURLConnection = url.openConnection() as HttpURLConnection
            con.addRequestProperty(KEY, API)

            println("u ${con.url}")

            //val reader = BufferedReader(InputStreamReader(/*con.inputStream*/))
            var temp: String? = null

//            while ({ temp = reader.readLine(); temp }() != null) raw += temp
//            reader.close()

            println("raw : $raw")
//            Toast.makeText(context, raw, Toast.LENGTH_LONG).show()

            val obj = JsonParser().parse(raw).asJsonObject //JSONObject(raw)

            //return null
            return if (obj.get(RESPONSE).asInt == ALL_GOOD) obj else null
        }
    }
}
