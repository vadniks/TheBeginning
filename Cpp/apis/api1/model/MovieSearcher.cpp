
#include "MovieSearcher.hpp"

MovieSearcher::MovieSearcher(QString const& title, void* parameter, request_callback callback) {
    manager = new QNetworkAccessManager();
    this->callback = callback;
    this->parameter = parameter;
    query(title);
}

MovieSearcher::~MovieSearcher() { delete manager; }

void MovieSearcher::query(QString const& title) const {
    QEventLoop eventLoop;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    auto* reply = manager->get(QNetworkRequest(QUrl(
        QString::asprintf("http://www.omdbapi.com/?t=%s&apikey=", title.toUtf8().constData())
    )));
    eventLoop.exec();
    onRequestFinished(reply);
}

void MovieSearcher::onRequestFinished(QNetworkReply* reply) const {
    if (reply->error() == QNetworkReply::NoError)
        parseReply(reply->readAll());
    else
        callback(parameter, nullptr);
    delete reply;
}

void MovieSearcher::parseReply(const QByteArray& reply) const {
    auto json = QJsonDocument::fromJson(reply).object();
    QJsonValueRef resultRefs[FIELDS] = {
        json["Title"],
        json["Released"],
        json["Rated"],
        json["Runtime"],
        json["Genre"],
        json["Director"],
        json["Writer"],
        json["Country"]
    };
    QString results[FIELDS];
    for (unsigned i = 0; i < FIELDS; results[i++] =
        resultRefs[i].isString() ? resultRefs[i].toString() : QString(NOT_FOUND));
    callback(parameter, results);
}
