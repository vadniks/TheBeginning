
#ifndef MAIN_VIEW
#define MAIN_VIEW

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "../consts.hpp"

class MainView : public QMainWindow {
    Q_OBJECT
private:
    QLabel* appName;
    QLineEdit* title;
    QPushButton* queryButton;
    QPushButton* clearButton;
    QLabel* released;
    QLabel* rated;
    QLabel* runtime;
    QLabel* genre;
    QLabel* director;
    QLabel* writer;
    QLabel* country;

public:
    explicit MainView();
    ~MainView() override;

private slots:
    void query();
    void clear();

private:
    void onQueryCompleted(QString* results);
};

#endif
