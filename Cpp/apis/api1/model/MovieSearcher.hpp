
#ifndef MODEL
#define MODEL

#include <QEventLoop>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include "../utils.hpp"
#include "../consts.hpp"

using request_callback = void (*)(void*, QString*);

class MovieSearcher {
private:
    QNetworkAccessManager* manager;
    void* parameter;
    request_callback callback;

public:
    static const_u FIELDS = 8;

public:
    MovieSearcher(QString const& title, void* parameter, request_callback callback);
    ~MovieSearcher();
    void query(QString const& title) const;
    void onRequestFinished(QNetworkReply* reply) const;
    void parseReply(const QByteArray& reply) const;
};

#endif
