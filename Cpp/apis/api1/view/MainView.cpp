
#include <QBoxLayout>
#include "MainView.hpp"
#include "../model/MovieSearcher.hpp"

MainView::MainView() : QMainWindow() {
    auto* center = new QWidget(this);

    QLayout* layout = new QVBoxLayout(center);
    layout->addWidget(appName = new QLabel(QString(APP_NAME)));

    auto* horizontal = new QHBoxLayout(center);

    title = new QLineEdit(center);
    title->setPlaceholderText(QString(MOVIE_TITLE));
    horizontal->addWidget(title);

    horizontal->addWidget(queryButton = new QPushButton(QString(SEARCH), center));
    QObject::connect(queryButton, SIGNAL(clicked(bool)), this, SLOT(query()));

    horizontal->addWidget(clearButton = new QPushButton(QString(CLEAR), center));
    QObject::connect(clearButton, SIGNAL(clicked(bool)), this, SLOT(clear()));

    layout->addItem(horizontal);
    layout->addWidget(released = new QLabel());
    layout->addWidget(rated = new QLabel());
    layout->addWidget(runtime = new QLabel());
    layout->addWidget(genre = new QLabel());
    layout->addWidget(director = new QLabel());
    layout->addWidget(writer = new QLabel());
    layout->addWidget(country = new QLabel());

    setCentralWidget(center);
    show();
}

MainView::~MainView() {
    delete appName;
    delete title;
    delete queryButton;
    delete clearButton;
    delete released;
    delete rated;
    delete runtime;
    delete genre;
    delete director;
    delete writer;
    delete country;
}

void MainView::onQueryCompleted(QString* results) {
    bool b = results != nullptr;
    auto a = [results, b](unsigned i) { return b ? results[i] : QString(NOT_FOUND); };

    title->setText(a(0));
    released->setText(a(1));
    rated->setText(a(2));
    runtime->setText(a(3));
    genre->setText(a(4));
    director->setText(a(5));
    writer->setText(a(6));
    country->setText(a(7));
}

void MainView::query() {
    MovieSearcher(title->text(), this, [](void* mainView, QString* results) {
        static_cast<MainView*>(mainView)->onQueryCompleted(results);
    });
}

void MainView::clear() { title->setText(""); }
