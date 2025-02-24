package com.some.hw4a2

import android.content.SharedPreferences
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.preference.PreferenceManager
import android.support.annotation.DrawableRes
import android.text.Editable
import android.view.Menu
import android.view.MenuItem
import android.widget.ArrayAdapter
import android.widget.Toast

import kotlinx.android.synthetic.main.activity_main.*

import java.io.*
import java.nio.charset.Charset

import javax.crypto.Cipher
import javax.crypto.spec.IvParameterSpec
import javax.crypto.spec.SecretKeySpec

/**
 * @author Vad Nik.
 * @version dated July 14, 2018.
 * @link github.com/vadniks
 *
 * Homework 5 based on homework 4.
 *
 * For task 3 open options menu.
 */
class MainActivity : AppCompatActivity() {
    private lateinit var sh: SharedPreferences
    //Homework 5 changes:
    private lateinit var db: SQL
    //Homework 5 changes:
    private val CITY: Array<String> = arrayOf("London", "Paris")
    //Homework 5 changes:
    private val WEATHER: Array<String> = arrayOf("sunny", "rainy")

    // fun - function.
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        sh = PreferenceManager.getDefaultSharedPreferences(this)

        //Homework 5 changes:
        db = SQL(this)

        textView.text = Editable.Factory.getInstance().newEditable(getCity())
        //Homework 5 changes:
        textView.setAdapter(ArrayAdapter<String>(this, android.R.layout.simple_dropdown_item_1line, CITY))
        //Homework 5 changes:
        textView.threshold = 0
        textView.setOnItemClickListener { _, _, _, _ -> saveCity(textView.text.toString()) }

        save.isEnabled = false

        save.setOnClickListener { _ -> saveImage(toBitmap(R.drawable.avatar), "avatar.png") }

        load.isEnabled = false

        load.setOnClickListener { _ ->
            val bitmap: Bitmap? = loadImage("avatar.png")

            if (bitmap == null) {
                Toast.makeText(this@MainActivity, "File doesn't exists!", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            image.setImageBitmap(bitmap)
            Toast.makeText(this, "Done", Toast.LENGTH_SHORT).show()
        }

        delete.isEnabled = false

        delete.setOnClickListener { _ -> deleteImage("avatar.png") }
    }

    private fun saveCity(city: String) {
        val ed: SharedPreferences.Editor = sh.edit()
        ed.putString("selectedCity", city)
        ed.apply()

        //Homework 5 changes:
        try {
            if (!isRawStored(city)) db.insert(city, WEATHER[CITY.indexOf(city)])
        } catch (ex: Exception) {
            Toast.makeText(this, "Enter one of ${CITY[0]} and ${CITY[1]}", Toast.LENGTH_LONG).show()
        }
    }

    //Homework 5 changes:
    private fun isRawStored(city: String): Boolean = db.getElement(city) != null

    //Homework 5 changes:
    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menu!!.add(0, 0, 0, "update") //For task 3.
        menu.add(0, 1, 0, "show all")
        return super.onCreateOptionsMenu(menu)
    }

    //Homework 5 changes:
    override fun onOptionsItemSelected(item: MenuItem?): Boolean {
        if (item == null) return super.onOptionsItemSelected(item)

        when (item.itemId) {
            0 -> {
                val city: String = textView.text.toString()

                if (isRawStored(city)) db.edit(city, WEATHER[if (CITY.indexOf(city) == 0) 1 else 0], city)
            }
            1 -> {
                for (o: SQL.Element in db.getAll())
                    Toast.makeText(this, "${o.id} ${o.name} ${o.data}", Toast.LENGTH_LONG).show()
            }
        }
        return super.onOptionsItemSelected(item)
    }

    private fun getCity(): String {
        val str: String = sh.getString("selectedCity", "")

        if (str == "") return ""

        Toast.makeText(this, str, Toast.LENGTH_LONG).show()

        return str
    }

    private fun toBitmap(@DrawableRes drawable: Int): Bitmap = BitmapFactory.decodeResource(resources, drawable)

    private fun saveImage(image: Bitmap, fileName: String) {
        if (File(getFilePath(fileName)).exists()) {
            Toast.makeText(this, "File already exists!", Toast.LENGTH_SHORT).show()
            return
        }

        val out = FileOutputStream(getFilePath(fileName))
        image.compress(Bitmap.CompressFormat.PNG, 100, out)
        out.flush()
        out.close()

        Toast.makeText(this, "Done", Toast.LENGTH_SHORT).show()
    }

    private fun loadImage(fileName: String): Bitmap? {
        if (!File(getFilePath(fileName)).exists()) return null

        return BitmapFactory.decodeStream(FileInputStream(getFilePath(fileName)))
    }

    private fun deleteImage(fileName: String) {
        if (!File(getFilePath(fileName)).exists()) {
            Toast.makeText(this, "File doesn't exists!", Toast.LENGTH_SHORT).show()
            return
        }

        File(getFilePath(fileName)).delete()

        Toast.makeText(this, "Done", Toast.LENGTH_SHORT).show()
    }

    private fun getFilePath(fileName: String): String = "${this.applicationContext.filesDir.path}/$fileName"

    private fun encrypt(msg: String): String {
        val iv = IvParameterSpec("RandomInitVector".toByteArray(Charset.forName("UTF-8")))
        val sks = SecretKeySpec("Bar12345Bar12345".toByteArray(Charset.forName("UTF-8")), "AES")
        val cipher = Cipher.getInstance("AES/CBC/PKCS5PADDING")
        cipher.init(Cipher.ENCRYPT_MODE, sks, iv)

        return byteArrayToHex(cipher.doFinal(msg.toByteArray(Charset.forName("UTF-8"))))!!
    }

    private fun decrypt(encrypted: String): String {
        val iv = IvParameterSpec("RandomInitVector".toByteArray(Charset.forName("UTF-8")))
        val sks = SecretKeySpec("Bar12345Bar12345".toByteArray(Charset.forName("UTF-8")), "AES")
        val cipher = Cipher.getInstance("AES/CBC/PKCS5PADDING")
        cipher.init(Cipher.DECRYPT_MODE, sks, iv)

        return String(cipher.doFinal(hexToByteArray(encrypted)))
    }

    private fun byteArrayToHex(ba: ByteArray): String? {
        if (ba.isEmpty()) return null

        val sb = StringBuilder(ba.size * 2)
        var hexNumber: String
        for (aBa in ba) {
            hexNumber = "0" + Integer.toHexString(0xff and aBa.toInt())

            sb.append(hexNumber.substring(hexNumber.length - 2))
        }
        return sb.toString()
    }

    private fun hexToByteArray(str: String): ByteArray? {
        if (str.isEmpty()) return null

        val ba = ByteArray(str.length.div(2))
        for ((i: Int, o) in ba.withIndex())
            ba[i] = str.substring(i.times(2), i.times(2).plus(2)).toInt(16).toByte()

        return ba
    }

//    private fun writeFile(file: ByteArray, filename: String) {
//        val out: FileOutputStream = openFileOutput(filename, Context.MODE_PRIVATE)
//        out.write(file)
//        out.flush()
//        out.close()
//    }
//
//    private fun toByteArray(file: File): ByteArray {
//        val `in` = FileInputStream(file)
//        `in`.
//    }
//
//    private fun getFile(filename: String): File? {
//        return if (!File(applicationContext.filesDir, filename).exists()) {
//                    Toast.makeText(this, "This file doesn't exists!", Toast.LENGTH_LONG).show()
//                    null
//                } else
//                    File(applicationContext.filesDir, filename)
//
////        val br = BufferedReader(FileReader(filename))
////        var text: String? = null
////        var line: String? = null
////
////        while ({ line = br.readLine(); line }() != null) text += line
//    }
}
