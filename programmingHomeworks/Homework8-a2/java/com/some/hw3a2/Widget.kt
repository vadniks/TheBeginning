package com.some.hw3a2

import android.app.PendingIntent
import android.appwidget.AppWidgetManager
import android.appwidget.AppWidgetProvider
import android.content.Context
import android.content.Intent
import android.view.View
import android.widget.RemoteViews

/**
 * @author Vad Nik.
 * @version dated July 25, 2018.
 * @link github.com/vadniks
 */
class Widget : AppWidgetProvider() {

    override fun onUpdate(context: Context, appWidgetManager: AppWidgetManager, appWidgetIds: IntArray) {
        // There may be multiple widgets active, so update all of them
        for (appWidgetId in appWidgetIds)
            updateAppWidget(context, appWidgetManager, appWidgetId)
    }

    override fun onDeleted(context: Context, appWidgetIds: IntArray) {
        // When the user deletes the widget, delete the preference associated with it.
        for (appWidgetId in appWidgetIds)
            WidgetConfigureActivity.saveIsChecked(context, appWidgetId, false)
    }

    override fun onEnabled(context: Context) {
        // Enter relevant functionality for when the first widget is created
    }

    override fun onDisabled(context: Context) {
        // Enter relevant functionality for when the last widget is disabled
    }

    companion object {

        internal fun updateAppWidget(context: Context, appWidgetManager: AppWidgetManager, appWidgetId: Int) {
            // Construct the RemoteViews object
            val views = RemoteViews(context.packageName, R.layout.widget)

            views.setTextViewText(R.id.appwidget_text, "Some weather")
            views.setImageViewResource(R.id.widgetImage, R.drawable.weather)

            views.setOnClickPendingIntent(R.id.widgetL,
                    PendingIntent.getActivity(context, System.currentTimeMillis().toInt(),
                            Intent(context, WidgetConfigureActivity::class.java)
                                    .setAction(AppWidgetManager.ACTION_APPWIDGET_CONFIGURE)
                                    .putExtra(AppWidgetManager.EXTRA_APPWIDGET_ID, appWidgetId),
                            PendingIntent.FLAG_UPDATE_CURRENT))

            if (WidgetConfigureActivity.loadIsChecked(context, appWidgetId)) {
                views.setViewVisibility(R.id.widText, View.VISIBLE)
                views.setTextViewText(R.id.widText, "Some pressure")
            } else
                views.setViewVisibility(R.id.widText, View.INVISIBLE)

            // Instruct the widget manager to update the widget
            appWidgetManager.updateAppWidget(appWidgetId, views)
        }
    }
}
