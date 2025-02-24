/*************************************************
 **  Created by Vad Nik on 02-Oct-18.
 *************************************************/

#ifndef NOTES_VIEWWINDOW_H
#define NOTES_VIEWWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QWidget>
#include "../../util/ListItem.h"
#include "../mainWindow/MainWindow.h"
#include "../../util/consts.h"
#include "../../util/IllegalStateException.h"

class ViewWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewWindow(QMainWindow *parent, ListItem item);
    ~ViewWindow() override;

public slots:
    void onDoneClick();
    void onCancelClick();
    void onDeleteClick();

private:
    QWidget *center;
    QMainWindow *parent;
    ListItem curItem;
    QLineEdit *titleT;
    QPlainTextEdit *textT;

private:
    QVBoxLayout * makeMainLayout(QVBoxLayout *textBar, QHBoxLayout *buttonBar);
    QVBoxLayout * makeTextBar();
    QHBoxLayout * makeButtonBar();
};


#endif //NOTES_VIEWWINDOW_H
