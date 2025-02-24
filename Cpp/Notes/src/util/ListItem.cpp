#include <utility>

/*************************************************
 **  Created by Vad Nik on 29-Sep-18.
 *************************************************/

#include "ListItem.h"

ListItem::ListItem(int id, QString title, QString text)
{
    this->id = id;
    this->title = std::move(title);
    this->_text = std::move(text);
}

int ListItem::getId()
{
    return this->id;
}

QString *ListItem::getTitle()
{
    return &this->title;
}

QString *ListItem::getText()
{
    return &this->_text;
}

void ListItem::setId(int id)
{
    this->id = id;
}

void ListItem::setTitle(QString *title)
{
    this->title = *title;
}

void ListItem::setText(QString *text)
{
    this->_text = *text;
}

QDataStream *ListItem::toDataStream()
{
    auto *out = new QDataStream();
    *out << quint32(id) << title << _text;

    return out;
}

ListItem ListItem::fromDataStream(QDataStream *stream)
{
    int id;
    QString title;
    QString text;

    *stream >> id >> title >> text;
    ListItem item(id, title, text);
    return item;
}

ListItem::~ListItem() = default;
