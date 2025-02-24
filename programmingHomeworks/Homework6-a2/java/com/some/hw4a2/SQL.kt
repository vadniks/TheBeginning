package com.some.hw4a2

import android.content.ContentValues
import android.content.Context
import android.database.Cursor
import android.database.sqlite.SQLiteDatabase
import android.database.sqlite.SQLiteOpenHelper

/**
 * @author Vad Nik.
 * @version dated July 14, 2018.
 * @link github.com/vadniks
 */

private const val TABLE_NAME: String = "hw5a2"
private const val ID: String = "id"
private const val NAME: String = "name"
private const val DATA: String = "data" //Can be used to store weather or JSON text
private const val CREATE_TABLE: String =
        "CREATE TABLE IF NOT EXISTS $TABLE_NAME (" +
        "$ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,\n" +
        "$NAME TEXT NOT NULL,\n" +
        "$DATA TEXT NOT NULL)"

class SQL(context: Context) : SQLiteOpenHelper(context, "hw5a2", null, 1) {

    /**
     * Constructor's body like:
     * <code>
     *     SQL(...) {
     *         onCreate(...)
     *     }
     * </code>
     * in java
     */
    init {
        onCreate(this.writableDatabase)
    }

    //Unit = void in java.
    override fun onCreate(db: SQLiteDatabase?): Unit = db?.execSQL(CREATE_TABLE)!!

    override fun onUpgrade(db: SQLiteDatabase?, oldVersion: Int, newVersion: Int) {
        db?.execSQL("DROP TABLE IF EXISTS $TABLE_NAME")
        onCreate(db)
    }

    internal fun getAll(): ArrayList<Element> {
        val db: SQLiteDatabase = this.readableDatabase
        val cursor: Cursor? = db.rawQuery("SELECT * FROM $TABLE_NAME", null)

        val arr = ArrayList<Element>()

        if (cursor == null) return arr

        //if (cursor != null && cursor.moveToFirst()) {
            while (cursor.moveToNext()) arr.add(Element(cursor.getInt(cursor.getColumnIndex(ID)),
                    cursor.getString(cursor.getColumnIndex(NAME)), cursor.getString(cursor.getColumnIndex(DATA))))
            cursor.close()
        //}
        return arr
    }

    /**
     * @return null if there's no element with the given name in db.
     */
    internal fun getElement(name: String): Element? {
        val cursor: Cursor? = this.readableDatabase
                .rawQuery("SELECT $ID, $NAME, $DATA FROM $TABLE_NAME WHERE $NAME = '$name'", null)

        return if (cursor != null && cursor.moveToFirst()) {
                    val element = Element(cursor.getInt(cursor.getColumnIndex(ID)), cursor.getString(cursor.getColumnIndex(NAME)),
                            cursor.getString(cursor.getColumnIndex(DATA)))
                    cursor.close()
                    element
                } else null
    }

    internal fun insert(name: String, data: String): Int {
        val values = ContentValues()
        values.put(NAME, name)
        values.put(DATA, data)

        println("insert")

        return this.writableDatabase.insert(TABLE_NAME, null, values).toInt()
    }

    internal fun delete(name: String): Unit = this.writableDatabase.execSQL("DELETE FROM $TABLE_NAME WHERE $NAME = '$name'")

    internal fun edit(prev: String, data: String, new: String): Unit =
            this.writableDatabase.execSQL("UPDATE $TABLE_NAME SET $NAME = '$new', $DATA = '$data' WHERE $NAME = '$prev'")

    internal fun deleteAll() {
        this.writableDatabase.execSQL("DROP TABLE IF EXISTS $TABLE_NAME")
        onCreate(this.writableDatabase)
    }

    /**
     * There's no static classes with constructors in kotlin. That's why I HAVE TO write usually classes inside others.
     * Static classes in kotlin are called objects like
     * <code>internal object SomeObject</code>
     * but they cannot be with constructors.
     */
    internal class Element(var id: Int, var name: String, var data: String)
}
