#ifndef HBHTTP_H
#define HBHTTP_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QMap>
#include <QUrlQuery>

typedef std::function<void(QString)> callback;

class HBHttp : public QObject
{
    Q_OBJECT
public:
    explicit HBHttp(QObject *parent = nullptr);

    void Get(QString urlStr, QUrlQuery param);

    static QString HBGet(QString urlStr, QUrlQuery param);

    void HB_get(QString urlStr, QUrlQuery param, callback func);

private slots:
    void _HB_get(QString urlStr, QUrlQuery param, callback func);
signals:
    void signal_HB_get(QString urlStr, QUrlQuery param, callback func);


private:
    QNetworkAccessManager *m_manager;

};

#endif // HBHTTP_H
