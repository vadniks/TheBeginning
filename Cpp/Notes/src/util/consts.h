/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#ifndef NOTES_CONSTS_H
#define NOTES_CONSTS_H

#pragma once

//Defaults:
#define DEF_WIN_W                 350
#define DEF_WIN_H                 450
#define DEF_FONT_SIZE             14
#define APP_ICON_PATH             ":/resources/notes.png"

//Alerts:
#define ALERT_WIN_TITLE_WARNING   "Warning!"
#define ALERT_TEXT_EMPTY          "One of the text fields is empty!"
#define ALERT_ALRD_EXISTS         "This note already exists!"
#define ALERT_TEXT_CHANGED        "One of the texts has been changed.\nDo you want to save changes?"
#define ALERT_BUTTON_OK           "OK"
#define ALERT_BUTTON_CANCEL       "Cancel"

//Exceptions:
#define ILLEGAL_STATE_EXCEPTION   "IllegalStateException"

//Database: //TODO: add password lock.
#define DB_TYPE                   "QSQLITE"
#define DB_FILE_NAME              "notes.db"
#define DB_FILE_NAME_EXT          "./" + DB_FILE_NAME
#define DB_NAME                   "notes"
#define DB_USER_NAME              "Admin"
#define DB_HOST_NAME              "localhost"
#define DB_PASSWORD               "password"
#define DB_ID                     "id"
#define DB_TITLE                  "title"
#define DB_TEXT                   "text"

//Main window:
#define MAIN_WIN_TITLE            "Notes"
#define MAIN_LIST_W               340
#define MAIN_LIST_H               448
#define MAIN_CREATE_BUTTON_TEXT   "Create note"

//Create window:
#define CREATE_WIN_TITLE          MAIN_CREATE_BUTTON_TEXT
#define CREATE_DONE_BUTTON_TEXT   "Done"
#define CREATE_CANCEL_BUTTON_TEXT ALERT_BUTTON_CANCEL
#define CREATE_TITLE_HINT         "Title"
#define CREATE_TEXT_HINT          "Text"
#define CREATE_ID_NAME            DB_ID
#define CREATE_TITLE_NAME         DB_TITLE
#define CREATE_TEXT_NAME          DB_TEXT

//ViewWindow:
#define VIEW_WIN_TITLE            "Edit"
#define VIEW_EDIT_BUTTON_TEXT     VIEW_WIN_TITLE
#define VIEW_CANCEL_BUTTON_TEXT   CREATE_CANCEL_BUTTON_TEXT
#define VIEW_DELETE_BUTTON_TEXT   "Delete"
#define VIEW_TITLE_HINT           CREATE_TITLE_HINT
#define VIEW_TEXT_HINT            CREATE_TEXT_HINT

#endif //NOTES_CONSTS_H
