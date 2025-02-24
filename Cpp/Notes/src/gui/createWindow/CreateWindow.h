/*************************************************
 **  Created by Vad Nik on 26-Sep-18.
 *************************************************/

#ifndef NOTES_CREATEWINDOW_H //TODO: unterminated conditional directive.
#define NOTES_CREATEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QListWidgetItem>
#include <QString>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QMessageBox>
#include "../mainWindow/MainWindow.h"
#include "../../util/consts.h"
#include "../../util/IllegalStateException.h"

class CreateWindow: public QMainWindow
{
    Q_OBJECT

private:
    QMainWindow *parent;
    QWidget *center;
    QLineEdit *titleT;
    QPlainTextEdit *textT;

public:
    explicit CreateWindow(QMainWindow *parent);
    ~CreateWindow() override;

public slots:
    void onDoneClicked();
    void onCancelClicked();

private:
    QVBoxLayout * makeMainLayout(QLayout *textBar, QLayout *buttonBar);
    QHBoxLayout * makeButtonBar();
    QVBoxLayout * makeTextBar();
    QListWidgetItem * createItem(const QString &title, const QString &text);
    void showAlert(const QString &title, const QString &msg);
};


#endif //NOTES_CREATEWINDOW_H
