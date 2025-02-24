/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#include <QApplication>
#include <QtCore>
#include <QIcon>
#include <QFile>
#include "gui/mainWindow/MainWindow.h"
#include "util/consts.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QApplication::setWindowIcon(QIcon(APP_ICON_PATH));

    MainWindow window;
    window.resize(DEF_WIN_W, DEF_WIN_H);
    window.setWindowTitle(MAIN_WIN_TITLE);
    window.Execute();

    return QApplication::exec();
}
