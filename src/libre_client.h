#ifndef LIBRE_CLIENT_H
#define LIBRE_CLIENT_H

#include <QObject>

class QNetworkAccessManager;

class LibreClient : public QObject
{
    Q_OBJECT
public:
    explicit LibreClient(QObject *parent = nullptr);

    void auth(const QString &host, const QString &login, const QString &pass);

signals:

private:
    QNetworkAccessManager *_network_access_manager = nullptr;
};

#endif // LIBRE_CLIENT_H
