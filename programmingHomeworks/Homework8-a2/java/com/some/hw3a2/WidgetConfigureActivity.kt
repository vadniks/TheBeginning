package com.some.hw3a2

import android.app.Activity
import android.appwidget.AppWidgetManager
import android.content.Context
import android.content.Intent
import android.os.Bundle
import android.preference.PreferenceManager
import android.view.View

import kotlinx.android.synthetic.main.widget_configure.*

/**
 * @author Vad Nik.
 * @version dted July 25, 2018.
 * @link github.com/vadniks
 */
class WidgetConfigureActivity : Activity() {
    private var mAppWidgetId = AppWidgetManager.INVALID_APPWIDGET_ID

    private var mOnClickListener: View.OnClickListener = View.OnClickListener { _ ->
        val context = this@WidgetConfigureActivity

        saveIsChecked(context, mAppWidgetId, chSP.isChecked)

        // It is the responsibility of the configuration activity to update the app widget
        val appWidgetManager = AppWidgetManager.getInstance(context)
        Widget.updateAppWidget(context, appWidgetManager, mAppWidgetId)

        // Make sure we pass back the original appWidgetId
        val resultValue = Intent()
        resultValue.putExtra(AppWidgetManager.EXTRA_APPWIDGET_ID, mAppWidgetId)
        setResult(Activity.RESULT_OK, resultValue)
        finish()
    }

    public override fun onCreate(icicle: Bundle?) {
        super.onCreate(icicle)

        // Set the result to CANCELED.  This will cause the widget host to cancel
        // out of the widget placement if the user presses the back button.
        setResult(Activity.RESULT_CANCELED)

        setContentView(R.layout.widget_configure)
        btDone.setOnClickListener(mOnClickListener)

        // Find the widget id from the intent.
        val intent = intent
        val extras = intent.extras
        if (extras != null)
            mAppWidgetId = extras.getInt(AppWidgetManager.EXTRA_APPWIDGET_ID, AppWidgetManager.INVALID_APPWIDGET_ID)

        // If this activity was started with an intent without an app widget ID, finish with an error.
        if (mAppWidgetId == AppWidgetManager.INVALID_APPWIDGET_ID) {
            finish()
            return
        }

        chSP.isChecked = loadIsChecked(this@WidgetConfigureActivity, mAppWidgetId)
    }

    companion object {
        private const val PREF_PREFIX_KEY = "appwidget_"

        // Write the prefix to the SharedPreferences object for this widget
        internal fun saveIsChecked(context: Context, appWidgetId: Int, isChecked: Boolean) {
            val prefs = PreferenceManager.getDefaultSharedPreferences(context).edit()
            prefs.putBoolean(PREF_PREFIX_KEY + appWidgetId, isChecked)
            prefs.apply()
        }

        // Read the prefix from the SharedPreferences object for this widget.
        // If there is no preference saved, get the default from a resource
        internal fun loadIsChecked(context: Context, appWidgetId: Int): Boolean {
            val prefs = PreferenceManager.getDefaultSharedPreferences(context)
            return prefs.getBoolean(PREF_PREFIX_KEY + appWidgetId, false)
        }
    }
}

