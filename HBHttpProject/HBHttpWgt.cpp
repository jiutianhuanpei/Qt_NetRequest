#include "HBHttpWgt.h"
#include "ui_HBHttpWgt.h"
#include <Header.h>

HBHttpWgt::HBHttpWgt(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HBHttpWgt)
{
    ui->setupUi(this);
    connect(ui->btn, &QPushButton::clicked, this, &HBHttpWgt::didClickedBtn);
    connect(ui->threadBtn, &QPushButton::clicked, this, &HBHttpWgt::didClickedThreadBtn);

    m_threadPool = new QThreadPool;

    m_http = new HBHttp;

}

void HBHttpWgt::didClickedBtn()
{
    QUrlQuery query;
    query.addQueryItem("stu_name", "二黑");
    //m_http->Get("http://api.nnzhp.cn/api/user/stu_info", query);

//    QString response = HBHttp::HBGet("http://api.nnzhp.cn/api/user/stu_info", query);
//    qDebug() << response;

    m_http->HB_get("http://api.nnzhp.cn/api/user/stu_info", query, [&](QString response) {
        qDebug() << response;
    });


}

void HBHttpWgt::didClickedThreadBtn()
{
    QtConcurrent::run(m_threadPool, [&] {
        QUrlQuery query;
        query.addQueryItem("stu_name", "二黑");
        //m_http->Get("http://api.nnzhp.cn/api/user/stu_info", query);
//        QString response = HBHttp::HBGet("http://api.nnzhp.cn/api/user/stu_info", query);
//        qDebug() << response;
        m_http->HB_get("http://api.nnzhp.cn/api/user/stu_info", query, [&](QString response) {
            qDebug() << response;
        });
    });
}


HBHttpWgt::~HBHttpWgt()
{
    delete ui;
}

