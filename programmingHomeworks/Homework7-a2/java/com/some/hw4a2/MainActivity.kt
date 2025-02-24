package com.some.hw3a2

import android.annotation.SuppressLint
import android.content.ComponentName
import android.content.Context
import android.content.Intent
import android.content.ServiceConnection
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.os.IBinder
import android.widget.TextView

import kotlinx.android.synthetic.main.activity_main.*

// Sorry for a lot of comments and unused code.
// Tested on device with android 5.1.1 (API 22)

/**
 * @author Vad Nik.
 * @version dated July 7, 2018.
 * @link github.com/vadniks
 */
class MainActivity : AppCompatActivity() {
    private lateinit var sconn: ServiceConnection
    private lateinit var service: Service

    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        cityF = city
        detailsF = details

        // Hardcoded text just for simplification.
        city.text = "none"
        details.text = "none"
        button.isEnabled = false

        sconn = object : ServiceConnection {
            override fun onServiceDisconnected(name: ComponentName?) {}

            override fun onServiceConnected(name: ComponentName?, serv: IBinder) {
                service = (serv as Service.BindeR).service
                city.text = service.city
                details.text = service.details
            }
        }

        bindService(Intent(this, Service::class.java), sconn, Context.BIND_AUTO_CREATE)

       // button.setOnClickListener { _: View? -> showDialog() }
    }

    override fun onStop() {
        super.onStop()
        unbindService(sconn)
    }

    //private fun showDialog(): Unit = Dialog().show(fragmentManager, "dialogHw3a2")

//    class Dialog : DialogFragment() {
//        private var selected: String? = null
//
//        override fun onCreateView(inflater: LayoutInflater?, container: ViewGroup?, savedInstanceState: Bundle?): View {
//            dialog.setTitle(R.string.choose_city)
//
//            val view: View = inflater?.inflate(R.layout.layout_dialog, container)!!
//            view.btDone.setOnClickListener { _: View? -> this done view }
//            view.actv.setAdapter(this createAdapter view)
//            view.actv.setOnItemClickListener { _, _, _, _ ->
//                selected = view.actv.text.toString() }
//
//            return view
//        }
//
//        private infix fun done(view: View) {
//            selected = view.actv.text.toString()
//
//            if (selected == null || selected == "") {
//                Toast.makeText(view.context, getString(R.string.textEmpty), Toast.LENGTH_LONG).show()
//                return
//            }
//
//            //Kotlin multithreading. DO NOT CHANGE ANYTHING IN THIS BLOCK!
//            val obj: JsonObject? = runBlocking { anc(view.context).await() }
//
//            //launch { obj = anc().await() }
//
//            //runBlocking { obj = MainActivity getJSON selected!! }
//
//            if (obj == null) {
//                Toast.makeText(view.context, getString(R.string.noPlace), Toast.LENGTH_LONG).show()
//                return
//            }
//
//            Handler(Looper.getMainLooper()).post { this render obj }
//        }
//
//        private fun anc(context: Context) = async(CommonPool) {
//            return@async MainActivity.getJSON(selected!!, context)
//        }
//
//        @SuppressLint("SetTextI18n")
//        private infix fun render(obj: JsonObject) {
//            //TODO: view is in layout_dialog not in activity_main
//
//            cityF.text = obj.get("name").asString.toUpperCase(Locale.US)
//
//            val det: JsonObject = obj.get("weather").asJsonArray[0].asJsonObject
//            val main: JsonObject = obj.get("main").asJsonObject
//
//            detailsF.text = "${det.get("description").asString.toUpperCase(Locale.US)}\n" +
//                    "Humidity: ${main.get("humidity").asString}% \n Pressure: ${main.get("pressure").asString}hPa\n" +
//                    "${String.format("%.2f", main.get("temp").asDouble)} ℃"
//
//            cityF.visibility = View.VISIBLE
//            detailsF.visibility = View.VISIBLE
//
//            dismiss()
//        }
//
//        private infix fun createAdapter(view: View): ArrayAdapter<String> =
//                ArrayAdapter(view.context, android.R.layout.simple_dropdown_item_1line, CITIES)
//    }

    //Instead of static definition.
    companion object {
        @SuppressLint("StaticFieldLeak")
        private lateinit var cityF: TextView
        @SuppressLint("StaticFieldLeak")
        private lateinit var detailsF: TextView
    }
}
