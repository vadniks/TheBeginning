#include <utility>

/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#include <utility>
#include "MainWindow.h"

MainWindow::MainWindow() = default;

MainWindow::~MainWindow() = default;

void MainWindow::Execute()
{
    QWidget *center = new QWidget(this);

    auto *layout = new QVBoxLayout(center);
    layout->addWidget(makeList());
    layout->addWidget(makeCreateBt());

    setCentralWidget(center);
    show();
}

void MainWindow::onItemClicked(QListWidgetItem *item)
{
//    int index = inters->getItemIndex(*item);
//
//    //TODO: test.
//    QMessageBox msg(this);
//    msg.setWindowTitle(QString::number(index));
//    msg.setText(item->text() + " " + inters->getItemTitle(item) + " " + QString::number(inters->getItemCount()));
//    msg.exec();

    auto *vwWin = new ViewWindow(this, inters->getData(item));
    vwWin->resize(DEF_WIN_W, DEF_WIN_H);
    vwWin->setWindowTitle(VIEW_WIN_TITLE);
    vwWin->show();
}

//TODO: add menu.

QListWidget * MainWindow::makeList()
{
    auto *list = new QListWidget(this);
    list->resize(MAIN_LIST_W, MAIN_LIST_H);
    list->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);

    QFont font = list->font();
    font.setPointSize(DEF_FONT_SIZE);

    list->setFont(font);

    //TODO: add SQL reading and loading from to list.
//    QStringList sList;
//    sList << "Item 1" << "Item 2";

    //sInters = SQLInteractions();
    SQLInteractions::init();

    auto *inters = new ListInteractions(list);
    //inters->addItems(sInters.loadItems());
    inters->addItems(SQLInteractions::loadItems());
    this->inters = inters;

    QObject::connect(list, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(onItemClicked(QListWidgetItem *)));

    list->show();

    return list;
}

QPushButton *MainWindow::makeCreateBt()
{
    auto *button = new QPushButton(this);
    button->setText(MAIN_CREATE_BUTTON_TEXT);

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(onCreateClicked()));

    return button;
}

void MainWindow::onCreateClicked()
{
    auto *crWin = new CreateWindow(this);
    crWin->resize(DEF_WIN_W, DEF_WIN_H);
    crWin->setWindowTitle(CREATE_WIN_TITLE);
    crWin->show();
}

void MainWindow::updateList()
{
    //TODO: delete his.
}

void MainWindow::addToList(QString title, QString text)
{
    //qDebug() << title << " - " << text;

    //sInters.putItem(ListItem(inters->getItemCount(), title, text));
    //inters->addItem(std::move(title), std::move(text));
    inters->addItem(std::move(title), std::move(text));
    //SQLInteractions::putItem(ListItem(inters->getItemCount(), title, text));
}

void MainWindow::edit(ListItem prev, ListItem nw)
{
    //sInters.updateItem(prev.getId(), nw);
    inters->edit(prev, nw);
    //SQLInteractions::updateItem(prev.getId(), nw);
}

void MainWindow::deleteItem(int index)
{
    //qDebug() << index;

    //SQLInteractions::deleteItem(index);
    //SQLInteractions::updateAll();
    //sInters.deleteItem(index);
    inters->removeItem(index);
}

void MainWindow::loadItems()
{

}

int MainWindow::getId(QString title)
{
    return inters->getItemIndex(std::move(title));
}

ListItem MainWindow::getItemFromList(int id)
{
    return inters->getData(inters->getItem(id));
}

vector<ListItem> MainWindow::getItemsFromList()
{
    return inters->getItems();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //SQLInteractions::deloadItems(getItemsFromList());
    event->accept();
}

void MainWindow::updateItem(int id, ListItem item)
{
    //SQLInteractions::updateItem(id, item);
}
