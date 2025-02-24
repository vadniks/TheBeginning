/*************************************************
 **  Created by Vad Nik on 05-Oct-18.
 *************************************************/

#include "SQLInteractions.h"

//SQLInteractions::SQLInteractions() = default;
//{
////    if (!createConnection())
////        throw -1;
////
////    if (!createDB())
////        throw -2;
//
//    //if (!hasCreated())
//        createConnection();
//    createDB();
//}

vector<ListItem> SQLInteractions::loadItems()
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    vector<ListItem> vector;

    QSqlQuery query(SQLInteractions::db);
    QString str = "SELECT id, title, text FROM " + QString::asprintf(DB_NAME);
    bool s = query.exec(str);

    if (!s)
        return vector;

    QSqlRecord rec = query.record();

    while (query.next()) {
        //qDebug() << " id " << query.value(rec.indexOf("id")).toInt();
        //vector.push_back(fromByteArray(query.value(rec.indexOf("data")).toByteArray()));
        vector.push_back(ListItem(query.value(rec.indexOf("id")).toInt(), query.value(rec.indexOf("title")).toString(),
                                  query.value(rec.indexOf("text")).toString()));
    }

    SQLInteractions::db.close();
//    int count = getItemCount();

//    if (count == 0)
//        return vector;

    //vector.reserve(count);
//    for (int i = 0; i < count; i++)
//        vector.push_back(getItem(i));

    return vector;
}

QSqlDatabase SQLInteractions::db;

bool SQLInteractions::createConnection()
{
    SQLInteractions::db = QSqlDatabase::addDatabase(DB_TYPE);
    SQLInteractions::db.setDatabaseName(QString::asprintf("./") + QString::asprintf(DB_NAME) + QString::asprintf(".db"));
    SQLInteractions::db.setUserName(DB_USER_NAME);
    SQLInteractions::db.setHostName(DB_HOST_NAME);
    SQLInteractions::db.setPassword(DB_PASSWORD);

    return SQLInteractions::db.open();
}

bool SQLInteractions::putItem(ListItem item)
{
    qDebug() << *item.getTitle() << " - " << *item.getText();

    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "INSERT INTO " + QString::asprintf(DB_NAME) + " (id, title, text) VALUES(?, ?, ?)";
    query.prepare(str);
    query.addBindValue(item.getId());
    query.addBindValue(*item.getTitle());
    query.addBindValue(*item.getText());
    //query.addBindValue(toByteArray(item), QSql::In | QSql::Binary);

    bool s = query.exec();

    db.close();

    return s;
}

bool SQLInteractions::createDB()
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "CREATE TABLE IF NOT EXISTS " + QString::asprintf(DB_NAME) + " (" +
                      "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," +
                      "title VARCHAR NOT NULL," +
                      "text VARCHAR NOT NULL" +
                  ")";

    bool s = query.exec(str);
    SQLInteractions::db.close();
    return s;
}

//TODO: update ListItem that stored in db when user edits and deletes items.

QByteArray SQLInteractions::toByteArray(ListItem &item)
{
    QJsonObject obj;
    obj[DB_ID] = item.getId();
    obj[DB_TITLE] = *item.getTitle();
    obj[DB_TEXT] = *item.getText();

    qDebug() << *item.getTitle();

    QJsonDocument doc(obj);
    return doc.toJson();
}

ListItem SQLInteractions::fromByteArray(QByteArray arr)
{
    QJsonObject obj = QJsonDocument::fromJson(arr).object();
    int id = obj[DB_ID].toInt();
    QString title = obj[DB_TITLE].toString();
    QString text = obj[DB_TEXT].toString();

    qDebug() << title;

    return ListItem(id, title, text);
}

ListItem SQLInteractions::getItem(QString title)
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "SELECT id, title, text FROM " + QString::asprintf(DB_NAME) + " WHERE title = ?";
    query.prepare(str);
    query.addBindValue(title);
    bool s = query.exec();

    SQLInteractions::db.close();

    if (!s)
        return ListItem();

    QSqlRecord rec = query.record();
    //QByteArray arr;

//    while (query.next())
//        arr = query.value(rec.indexOf(DB_ID)).toByteArray();

    ListItem item;

    if (query.first())
        //arr = query.value(rec.indexOf("data")).toByteArray();
        item = ListItem(query.value(rec.indexOf("id")).toInt(), query.value(rec.indexOf("title")).toString(),
                query.value(rec.indexOf("text")).toString());

    return item; //fromByteArray(arr);
}

bool SQLInteractions::updateItem(QString title, ListItem nw)
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "UPDATE " + QString::asprintf(DB_NAME) + " SET id = ?, title = ?, text = ? WHERE title = ?";
    query.prepare(str);
    //query.addBindValue(toByteArray(nw), QSql::In | QSql::Binary);
    query.addBindValue(nw.getId());
    query.addBindValue(*nw.getTitle());
    query.addBindValue(*nw.getText());
    query.addBindValue(title);

    bool s = query.exec();
    SQLInteractions::db.close();
    return s;
}

int SQLInteractions::getItemCount()
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "SELECT * FROM " + QString::asprintf(DB_NAME);
    bool s = query.exec(str);

    SQLInteractions::db.close();

    if (!s)
        return -1;

    int count = 0;
    while (query.next())
        count++;

    return count;
}

bool SQLInteractions::deleteItem(QString title)
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "DELETE FROM " + QString::asprintf(DB_NAME) + " WHERE title = ?";
    query.prepare(str);
    query.addBindValue(title);

    bool s = query.exec();
    SQLInteractions::db.close();
    return s;
}

bool SQLInteractions::hasCreated()
{
    if (FILE *file = fopen(DB_FILE_NAME, "r"))
    {
        fclose(file);
        return true;
    }
    return false;
}

void SQLInteractions::init()
{
    createConnection();
    createDB();
}

bool SQLInteractions::updateItemId(int prev, int nw)
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "UPDATE " + QString::asprintf(DB_NAME) + " SET id = ? WHERE id = ?";
    query.prepare(str);
    query.addBindValue(nw);
    query.addBindValue(prev);

    bool s = query.exec();
    SQLInteractions::db.close();
    return s;
}

void SQLInteractions::updateAll()
{
//    for (int i = 0; i < getItemCount(); i++) {
//        ListItem item = getItem(i);
//        int id = getItemIndex(*item.getTitle());
//        updateItem(id, item);
//        updateItemId(id, i);
//    }

    //qDebug() << " idx " << getItemIndex("b");
}

int SQLInteractions::getItemIndex(QString title)
{
    for (const auto &i : loadItems()) {
        if (QString::compare(*((ListItem) i).getTitle(), title))
            return ((ListItem) i).getId();
    }
    return 0;
}

void SQLInteractions::deloadItems(vector<ListItem> items)
{
    deleteAll();
    for (auto &i : items)
        putItem((ListItem) i);
}

void SQLInteractions::deleteAll()
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "DELETE FROM " + QString::asprintf(DB_NAME);

    query.exec(str);
    SQLInteractions::db.close();
}

//SQLInteractions::~SQLInteractions() = default;
//{
//    this->db.close();
//}
