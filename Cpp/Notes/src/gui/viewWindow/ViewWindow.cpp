/*************************************************
 **  Created by Vad Nik on 02-Oct-18.
 *************************************************/

#include "ViewWindow.h"

ViewWindow::ViewWindow(QMainWindow *parent, ListItem item) : QMainWindow(parent)
{
    this->curItem = item;

    QWidget *center = new QWidget(this);
    this->center = center;

    makeMainLayout(makeTextBar(), makeButtonBar());

    setCentralWidget(center);
    setWindowModality(Qt::WindowModality::WindowModal);

    this->parent = parent;
}

QVBoxLayout * ViewWindow::makeMainLayout(QVBoxLayout *textBar, QHBoxLayout *buttonBar)
{
    auto *root = new QVBoxLayout(center);
    root->addItem(textBar);
    root->addItem(buttonBar);

    return root;
}

QVBoxLayout *ViewWindow::makeTextBar()
{
    auto *titleT = new QLineEdit(this);
    titleT->setPlaceholderText(VIEW_TITLE_HINT);
    titleT->setText(*curItem.getTitle());
    titleT->setReadOnly(true);

    QFont font = titleT->font();
    font.setPointSize(DEF_FONT_SIZE);

    titleT->setFont(font);
    this->titleT = titleT;

    auto *textT = new QPlainTextEdit(this);
    textT->setPlaceholderText(VIEW_TEXT_HINT);
    textT->setPlainText(*curItem.getText());

    QFont font2 = textT->font();
    font2.setPointSize(DEF_FONT_SIZE);

    textT->setFont(font);
    this->textT = textT;

    auto *layout = new QVBoxLayout();
    layout->addWidget(titleT);
    layout->addWidget(textT);

    return layout;
}

QHBoxLayout *ViewWindow::makeButtonBar()
{
    auto *btEdit = new QPushButton(VIEW_EDIT_BUTTON_TEXT, this);
    auto *btCancel = new QPushButton(VIEW_CANCEL_BUTTON_TEXT, this);
    auto *btDelete = new QPushButton(VIEW_DELETE_BUTTON_TEXT, this);

    QObject::connect(btEdit, SIGNAL(clicked()), this, SLOT(onDoneClick())); //TODO: rename onDoneClick().
    QObject::connect(btCancel, SIGNAL(clicked()), this, SLOT(onCancelClick()));
    QObject::connect(btDelete, SIGNAL(clicked()), this, SLOT(onDeleteClick()));

    auto *layout = new QHBoxLayout();
    layout->addWidget(btEdit);
    layout->addWidget(btCancel);
    layout->addWidget(btDelete);

    return layout;
}

void ViewWindow::onDoneClick()
{
    if (titleT->text().length() == 0 && textT->toPlainText().length() == 0)
    {
        QMessageBox m(this);
        m.setWindowTitle(ALERT_WIN_TITLE_WARNING);
        m.setText(ALERT_TEXT_EMPTY);
        m.exec();
        return;
    }

    //try {
        ((MainWindow *) parent)->edit(curItem, ListItem(curItem.getId(), titleT->text(), textT->toPlainText()));
//    } catch (IllegalStateException &e) {
//        QMessageBox mb(this);
//        mb.setWindowTitle(ALERT_WIN_TITLE_WARNING);
//        mb.setText(ALERT_ALRD_EXISTS);
//        mb.exec();
//    }
    close();
}

void ViewWindow::onCancelClick()
{
    if (QString::compare(textT->toPlainText(), curItem.getText(), Qt::CaseInsensitive))
    {
        QMessageBox mb(QMessageBox::Question, ALERT_WIN_TITLE_WARNING, ALERT_TEXT_CHANGED,
                       QMessageBox::Yes | QMessageBox::No);

        switch (mb.exec())
        {
            case QMessageBox::Yes:
                onDoneClick();
                break;
            case QMessageBox::No:
                close();
                break;
            default:break;
        }
    }
    else
    {
        close();
    }
}

void ViewWindow::onDeleteClick()
{
    ((MainWindow *) parent)->deleteItem(curItem.getId());
    close();
}

ViewWindow::~ViewWindow() = default;
