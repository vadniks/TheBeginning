package com.some.hw3

import android.content.Context
import android.graphics.Color
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.v7.widget.DividerItemDecoration
import android.support.v7.widget.LinearLayoutManager
import android.view.*
import android.widget.TextView
import android.widget.Toast
import android.support.v7.widget.RecyclerView

/**
 * @author Vad Nik.
 * @version dated June 30, 2018.
 * @link github.com/vadniks
 */
class MainActivity : AppCompatActivity() {
    private var arr: ArrayList<Model> = ArrayList()
    private lateinit var rv: RecyclerView
    private var isInActionMode: Boolean = false
    //private val selected: ArrayList<Model> = ArrayList()
    private lateinit var adapter: Adapter
    private var wasDeleted: Boolean = false

    private var actModeCallBack: ActionMode.Callback? =
            object : ActionMode.Callback {
                override fun onActionItemClicked(mode: ActionMode, item: MenuItem): Boolean {
                    return when (item.itemId) {
                        R.id.contextDel -> {
                            this@MainActivity.delete()
                            mode.finish()
                            true
                        }
                        else -> false
                    }
                }

                override fun onCreateActionMode(mode: ActionMode, menu: Menu): Boolean {
                    mode.menuInflater.inflate(R.menu.menu_context_main, menu)
                    isInActionMode = true
                    return true
                }

                override fun onPrepareActionMode(mode: ActionMode?, menu: Menu?): Boolean = false

                override fun onDestroyActionMode(mode: ActionMode?) {
                    isInActionMode = false
                    if (wasDeleted)
                        wasDeleted = false
                    else {
                        for (o: Model in arr)
                            if (o.isSelected) {

                                println("     ${o.title} ${o.isSelected}")

                                //arr[o.id].isSelected = false

                                val m = Model(o.title, o.id, false)
                                arr[o.id] = m

                                println("     ${o.title} ${o.isSelected}")
                            }

                        adapter = Adapter(this@MainActivity, arr)
                        rv.adapter = adapter // This is needed to deselect all selected items if user didn't delete them
                    }
                    //this@MainActivity.actModeCallBack = null
                }
            }

    private fun delete() {
//        var isAny = false
//        for (o: Model in arr) {
//            //println(o.title + " " + o.isSelected)
//            if (o.isSelected) {
//                isAny = true
//                break
//            }
//        }

        //if (isAny) {
            val selected: ArrayList<Model> = ArrayList()

            for ((i: Int, o: Model) in arr.withIndex())
                if (o.isSelected) selected.add(o) //arr.remove(o)

            arr.removeAll(selected)

            //println("                 111")

            Toast.makeText(this, "${arr.size}", Toast.LENGTH_LONG).show()

//            adapter.clear()
//            adapter addAll arr
//            adapter.notifyDataSetChanged()
            adapter = Adapter(this, arr)
            rv.adapter = adapter
            wasDeleted = true
        //}
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        for (i in 0 until 6 step 1)
            arr.add(Model("Element $i", i))

        adapter = Adapter(this, arr)

        rv = findViewById(R.id.recV)
        rv.setHasFixedSize(true)
        rv.layoutManager = LinearLayoutManager(this)
        rv.adapter = adapter
        rv.addItemDecoration(DividerItemDecoration(this, LinearLayoutManager.VERTICAL))
    }

    inner class Adapter(private val context: Context, private val items: ArrayList<Model>) :
            RecyclerView.Adapter<MainActivity.Adapter.ViewHolder>() {

        infix fun addAll(items: ArrayList<Model>) = items.addAll(items)

        fun clear() = items.clear()

        override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
            val view: View = LayoutInflater.from(parent.context).inflate(R.layout.item_rec_view, parent, false)
            val viewHolder = ViewHolder(view)

            viewHolder.itemView.setOnClickListener { _ -> Toast.makeText(context, items[viewHolder.adapterPosition]
                    .title, Toast.LENGTH_SHORT).show() }

            if (actModeCallBack != null)
                viewHolder.itemView.setOnLongClickListener { _ -> startActionMode(actModeCallBack);false }

            return viewHolder
        }

        override fun getItemCount(): Int = items.size

        override fun onBindViewHolder(holder: ViewHolder, position: Int) {
            val model: Model = items[position]

            holder.text.text = items[position].title
            //holder.itemView.setBackgroundColor(if (model.isSelected) Color.CYAN else Color.WHITE)
            holder.itemView.setOnClickListener { _ ->
                if (isInActionMode) {
                    model.isSelected = !model.isSelected
                    holder.itemView.setBackgroundColor(if (model.isSelected) Color.CYAN else Color.WHITE)
                    items[position] = model
                } else
                    Toast.makeText(context, items[holder.adapterPosition].title, Toast.LENGTH_SHORT).show()

            }
        }

        inner class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
            var text: TextView = itemView.findViewById(R.id.itemText)
        }
    }

    inner class Model(var title: String, var id: Int, var isSelected: Boolean = false)

//    @Suppress("serial")
//    inner class Element(val name: String, val id: Int) : Serializable {
//
//        private infix fun toElement(row: String): Element = Element(row.split(" ")[0],
//                row.split(" ")[1].toInt())
//
//        infix fun toElement(items: ArrayList<String>): ArrayList<Element> {
//            val arr: ArrayList<Element> = ArrayList()
//
//            for (o: String in items)
//                arr.add(this toElement o)
//
//            return arr
//        }
//    }
//
//    inner class ListAdapter(context: Context, private val items: ArrayList<Element>) : BaseAdapter() {
//        private val li: LayoutInflater = context.getSystemService(Context.LAYOUT_INFLATER_SERVICE) as LayoutInflater
//
//        override fun getView(position: Int, convertView: View?, parent: ViewGroup?): View {
//            val view: View = convertView ?: li.inflate(R.layout.list_item, parent, false)
//            val element: Element = getItem(position)
//
//            (view.findViewById(android.R.id.text1) as TextView).text = element.name
//
//            return view
//        }
//
//        override fun getItem(position: Int): Element = items[position]
//
//        override fun getItemId(position: Int): Long = items[position].id.toLong()
//
//        override fun getCount(): Int = items.size
//
//        infix fun addAll(arr: ArrayList<Element>) = items.addAll(arr)
//
//        fun clear() = items.clear()
//    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        menuInflater.inflate(R.menu.menu_main, menu)

        menu.add(0, 1, 0, "Some")
        menu.add(0, 2, 1, "Some2")

        return super.onCreateOptionsMenu(menu)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId) {
            1 ->
                Toast.makeText(this, "Menu button 1", Toast.LENGTH_SHORT).show()
            2 ->
                Toast.makeText(this, "Menu button 2", Toast.LENGTH_SHORT).show()
            R.id.toolBBt1 ->
                Toast.makeText(this, "ToolBar button 1", Toast.LENGTH_SHORT).show()
            R.id.toolBBt2 ->
                Toast.makeText(this, "ToolBar button 2", Toast.LENGTH_SHORT).show()
        }
        return super.onOptionsItemSelected(item)
    }
}
