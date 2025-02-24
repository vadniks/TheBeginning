/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#ifndef NOTES_MAINWINDOW_H //TODO: unterminated conditional directive.
#define NOTES_MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStringList>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
#include <utility>
#include <vector>
#include "processing/ListInteractions.h"
#include "../../util/consts.h"
#include "../createWindow/CreateWindow.h"
#include "../viewWindow/ViewWindow.h"
#include "../../processing/SQLInteractions.h"

using namespace std;

class MainWindow: public QMainWindow
{
    Q_OBJECT

private:
    ListInteractions *inters;
    //SQLInteractions sInters;

public:
    MainWindow();
    ~MainWindow() override;

public:
    void closeEvent(QCloseEvent *event) override;

public:
    void Execute();
    void addToList(QString title, QString text); //TODO: add writing to SQL in this function.
    void edit(ListItem prev, ListItem nw);
    void deleteItem(int index);

    [[deprecated]]
    int getId(QString title);
    [[deprecated]]
    ListItem getItemFromList(int id);
    [[deprecated]]
    vector<ListItem> getItemsFromList();
    [[deprecated]]
    void updateItem(int id, ListItem item);

    [[deprecated("useless, directly add-remove operations do the trick")]]
    void updateList();

public slots:
    void onItemClicked(QListWidgetItem *item);
    void onCreateClicked();

private:
    QListWidget * makeList();
    QPushButton * makeCreateBt();
    void loadItems();
};


#endif //NOTES_MAINWINDOW_H
