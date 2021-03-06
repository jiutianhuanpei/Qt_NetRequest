#include "HBHttp.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>

HBHttp::HBHttp(QObject *parent) : QObject(parent)
{
    m_manager = new QNetworkAccessManager;

    //注册类型，用于 signal/slot 间的参数传递
    qRegisterMetaType<callback>("callback");
    qRegisterMetaType<QUrlQuery>("QUrlQuery");


    connect(this, &HBHttp::signal_HB_get, this, &HBHttp::_HB_get);

    //基础调用时打开
//    connect(m_manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply) {

//        QString response = reply->readAll();
//        qDebug() << response;
//    });
}

void HBHttp::Get(QString urlStr, QUrlQuery param)
{
    QUrl url(urlStr);
    url.setQuery(param);

    QNetworkRequest request(url);

    m_manager->get(request);
}

QString HBHttp::HBGet(QString urlStr, QUrlQuery param)
{
    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

    QUrl url(urlStr);
    url.setQuery(param);

    QNetworkRequest request(url);

    QNetworkReply *reply = manager.get(request);

    loop.exec();

    QString response = reply->readAll();
    return  response;
}


void HBHttp::HB_get(QString urlStr, QUrlQuery param, callback func)
{
    emit signal_HB_get(urlStr, param, func);
}

void HBHttp::_HB_get(QString urlStr, QUrlQuery param, callback func)
{
    QUrl url(urlStr);
    url.setQuery(param);

    QNetworkRequest request(url);
    QNetworkReply *reply = m_manager->get(request);

    //对 reply 添加信号监听，以便于一对一数据返回
    connect(reply, &QNetworkReply::finished, [&, reply, func] {

        QString response = reply->readAll();
        func(response);
        reply->deleteLater();
    });
}








