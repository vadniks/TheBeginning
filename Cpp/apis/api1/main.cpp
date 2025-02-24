
#include <QApplication>
#include "view/MainView.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MainView view;
    view.show();
    return QApplication::exec();
}
