package com.some.hw2a2

import android.os.Bundle
import android.support.design.widget.Snackbar
import android.support.design.widget.NavigationView
import android.support.v4.view.GravityCompat
import android.support.v7.app.ActionBarDrawerToggle
import android.support.v7.app.AppCompatActivity
import android.view.Menu
import android.view.MenuItem
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.app_bar_main.*
import kotlinx.android.synthetic.main.content_main.*

/**
 * @author Vad Nik.
 * @version dated July 4, 2018.
 * @link github.com/vadniks
 */

/*
 * Task 1 is in content_main.xml and styles in values (usual) folder.
 */
class MainActivity : AppCompatActivity(), NavigationView.OnNavigationItemSelectedListener {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        setSupportActionBar(toolbar)

        fab.setOnClickListener { view ->
            Snackbar.make(view, "Some action", Snackbar.LENGTH_LONG)
                    .setAction("Action", null).show()
        }

        someBt.setOnClickListener { view ->
            Snackbar.make(view, "Some button", Snackbar.LENGTH_LONG).show()
        }

        val toggle = ActionBarDrawerToggle(
                this, drawer_layout, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close)
        drawer_layout.addDrawerListener(toggle)
        toggle.syncState()

        nav_view.setNavigationItemSelectedListener(this)
    }

    override fun onBackPressed() {
        if (drawer_layout.isDrawerOpen(GravityCompat.START)) {
            drawer_layout.closeDrawer(GravityCompat.START)
        } else {
            super.onBackPressed()
        }
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.main, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        return when (item.itemId) {
            R.id.someMenuItem -> {
                Snackbar.make(findViewById(android.R.id.content), "Some menu item", Snackbar.LENGTH_LONG).show()
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    override fun onNavigationItemSelected(item: MenuItem): Boolean {
        // Handle navigation view item clicks here.


        when (item.itemId) {
            R.id.devs -> {
                Snackbar.make(findViewById(android.R.id.content), "Developers", Snackbar.LENGTH_LONG).show()
            }
            R.id.contact -> {
                Snackbar.make(findViewById(android.R.id.content), "Contact us", Snackbar.LENGTH_LONG).show()
            }
//            R.id.nav_slideshow -> {
//
//            }
//            R.id.nav_manage -> {
//
//            }
            R.id.nav_share -> {
                Snackbar.make(findViewById(android.R.id.content), "Share", Snackbar.LENGTH_LONG).show()
            }
            R.id.nav_send -> {
                Snackbar.make(findViewById(android.R.id.content), "Send", Snackbar.LENGTH_LONG).show()
            }
        }

        drawer_layout.closeDrawer(GravityCompat.START)
        return true
    }
}
