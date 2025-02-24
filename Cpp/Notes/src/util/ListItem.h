/*************************************************
 **  Created by Vad Nik on 29-Sep-18.
 *************************************************/

#ifndef NOTES_LISTITEM_H
#define NOTES_LISTITEM_H

#include <QString>
#include <QDataStream>

class ListItem
{

public:
    explicit ListItem(int id = 0, QString title = nullptr, QString text = nullptr);
    ~ListItem();

public:
    QString * getTitle();
    QString * getText();
    void setId(int id);
    void setTitle(QString *title);
    void setText(QString *text);
    QDataStream * toDataStream();
    static ListItem fromDataStream(QDataStream *stream);

    //[[deprecated("unsafe")]]
    int getId();

private:
    int id;
    QString title;
    QString _text;
};


#endif //NOTES_LISTITEM_H
