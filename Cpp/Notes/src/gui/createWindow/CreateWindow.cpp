/*************************************************
 **  Created by Vad Nik on 26-Sep-18.
 *************************************************/

#include "CreateWindow.h"

CreateWindow::CreateWindow(QMainWindow *parent) : QMainWindow(parent)
{
    QWidget *center = new QWidget(this);
    this->center = center;

    makeMainLayout(makeTextBar(), makeButtonBar());

    setCentralWidget(center);
    setWindowModality(Qt::WindowModality::WindowModal);

    this->parent = parent;
}

QVBoxLayout *CreateWindow::makeMainLayout(QLayout *textBar, QLayout *buttonBar)
{
    auto *root = new QVBoxLayout(center);
    root->addItem(textBar);
    root->addItem(buttonBar);

    return root;
}

QHBoxLayout *CreateWindow::makeButtonBar()
{
    auto *btDone = new QPushButton(CREATE_DONE_BUTTON_TEXT, this);
    auto *btCreate = new QPushButton(CREATE_CANCEL_BUTTON_TEXT, this);

    QObject::connect(btDone, SIGNAL(clicked()), this, SLOT(onDoneClicked()));
    QObject::connect(btCreate, SIGNAL(clicked()), this, SLOT(onCancelClicked()));

    auto *layout = new QHBoxLayout();
    layout->addWidget(btDone);
    layout->addWidget(btCreate);

    return layout;
}

QVBoxLayout *CreateWindow::makeTextBar()
{
    auto *titleT = new QLineEdit(this);
    titleT->setPlaceholderText(CREATE_TITLE_HINT);

    QFont font = titleT->font();
    font.setPointSize(DEF_FONT_SIZE);

    titleT->setFont(font);
    this->titleT = titleT;

    auto *textT = new QPlainTextEdit(this);
    textT->setPlaceholderText(CREATE_TEXT_HINT);
    //textT->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    QFont font2 = textT->font();
    font2.setPointSize(DEF_FONT_SIZE);

    textT->setFont(font);
    this->textT = textT;

    auto *layout = new QVBoxLayout();
    layout->addWidget(titleT);
    layout->addWidget(textT);

    return layout;
}

void CreateWindow::onDoneClicked()
{
    if (titleT->text().length() == 0 || textT->toPlainText().length() == 0) {
        showAlert(ALERT_WIN_TITLE_WARNING, ALERT_TEXT_EMPTY);
        return;
    }

    try {
        ((MainWindow *) parent)->addToList(titleT->text(), textT->toPlainText());
    } catch (IllegalStateException &e) {
        showAlert(ALERT_WIN_TITLE_WARNING, ALERT_ALRD_EXISTS);
        return;
    }

    close();
}

void CreateWindow::onCancelClicked()
{
    this->close();
}

QListWidgetItem *CreateWindow::createItem(const QString &title, const QString &text)
{
    auto *item = new QListWidgetItem(title + QString(" : ") + text);
    return item;
}

void CreateWindow::showAlert(const QString &title, const QString &msg)
{
    QMessageBox mBox(this);
    mBox.setWindowTitle(title);
    mBox.setText(msg);
    mBox.exec();
}

CreateWindow::~CreateWindow() = default;
