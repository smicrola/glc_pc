#include "libre_client.h"
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QNetworkReply>

LibreClient::LibreClient(QObject *parent)
    : QObject{parent}
{
    _network_access_manager = new QNetworkAccessManager(this);
}

void LibreClient::auth(const QString &host, const QString &login, const QString &pass)
{
    QNetworkRequest request(host + "/llu/auth/login");
    QVariantMap mp;
    mp.insert("email", login);
    mp.insert("password", pass);

    request.setRawHeader("version", "4.12.0");
    request.setRawHeader("product", "llu.android");
    request.setRawHeader("Content-Type", "application/json");

    QNetworkReply *reply = _network_access_manager->post(request, QJsonDocument::fromVariant(mp).toJson());
    connect(reply, &QNetworkReply::finished,
            this, [this, reply](){
        QByteArray bt = reply->readAll();
        qDebug()<< bt;
        reply->deleteLater();
    });
}
