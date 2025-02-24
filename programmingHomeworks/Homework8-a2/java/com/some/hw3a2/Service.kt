package com.some.hw3a2

import android.app.Service
import android.content.Context
import android.content.Intent
import android.os.Binder
import android.os.IBinder
import com.google.gson.JsonObject
import com.google.gson.JsonParser
import kotlinx.coroutines.experimental.async
import kotlinx.coroutines.experimental.runBlocking
import okhttp3.HttpUrl
import okhttp3.OkHttpClient
import okhttp3.Request
import java.net.HttpURLConnection
import java.net.URL
import java.util.*

/**
 * @author Vad Nik.
 * @version dated July 21, 2018.
 * @link github.com/vadniks
 */
class Service : Service() {
    private lateinit var binder: BindeR
    private var obj: JsonObject? = null

    val city: String?
        get() = obj?.get("name")?.asString?.toUpperCase(Locale.US)

    val details: String?
        get() =
            if (obj != null)
                obj?.get("weather")?.asJsonArray!![0].asJsonObject?.get("description")?.asString?.toUpperCase(Locale.US)
            else null

    override fun onCreate() {
        super.onCreate()
        binder = BindeR()
    }

    override fun onBind(intent: Intent?): IBinder? {
        loadJSON()
        return binder
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private fun loadJSON() {
        obj = runBlocking { anc().await() }
    }

    private fun anc() = async {
        return@async getJSON(CITIES[0], this@Service)
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

    inner class BindeR : Binder() {
        val service: com.some.hw3a2.Service
            get() = this@Service
    }

    private companion object {
        private val CITIES: Array<String> = arrayOf("London", "Paris")
        private const val API = ""
        private const val OPEN_WEATHER_MAP_API = "http://api.openweathermap.org/data/2.5/weather?q=%s&units=metric"
        private const val KEY = "x-api-key"
        private const val RESPONSE = "cod"
        private const val ALL_GOOD = 200
    }
}
