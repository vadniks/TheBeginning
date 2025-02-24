/*************************************************
 **  Created by Vad Nik on 05-Oct-18.
 *************************************************/

#ifndef NOTES_SQLINTERACTIONS_H
#define NOTES_SQLINTERACTIONS_H

#include <vector>
#include <QString>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include "../util/ListItem.h"
#include "../util/consts.h"

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>

using namespace std;

class SQLInteractions
{

private:
    static QSqlDatabase db;

//public:
//    SQLInteractions();
//    ~SQLInteractions();

public:
    static void init();
    static vector<ListItem> loadItems();
    static bool putItem(ListItem item);
    static ListItem getItem(QString title);
    static int getItemCount();
    static bool deleteItem(QString title);
    static int getItemIndex(QString title);
    static void deleteAll();
    static bool updateItem(QString title, ListItem nw);

    [[deprecated]]
    static bool updateItemId(int prev, int nw);
    [[deprecated]]
    static void updateAll();
    [[deprecated]]
    static void deloadItems(vector<ListItem> items);

private:
    static bool createConnection();
    static bool createDB();

    [[deprecated]]
    static QByteArray toByteArray(ListItem &item);
    [[deprecated]]
    static ListItem fromByteArray(QByteArray arr);
    [[deprecated]]
    static bool hasCreated();
};


#endif //NOTES_SQLINTERACTIONS_H
