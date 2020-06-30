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

    //基础调用
    void Get(QString urlStr, QUrlQuery param);


    //升级调用
    static QString HBGet(QString urlStr, QUrlQuery param);


    //终极调用
    void HB_get(QString urlStr, QUrlQuery param, callback func);

private slots:
    void _HB_get(QString urlStr, QUrlQuery param, callback func);
signals:
    void signal_HB_get(QString urlStr, QUrlQuery param, callback func);


private:
    QNetworkAccessManager *m_manager;

};

#endif // HBHTTP_H
