#ifndef HBHTTPWGT_H
#define HBHTTPWGT_H

#include <QWidget>
#include "HBHttp.h"
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>

QT_BEGIN_NAMESPACE
namespace Ui { class HBHttpWgt; }
QT_END_NAMESPACE

class HBHttpWgt : public QWidget
{
    Q_OBJECT

public:
    HBHttpWgt(QWidget *parent = nullptr);
    ~HBHttpWgt();

private:
    Ui::HBHttpWgt *ui;

    QThreadPool *m_threadPool;

    HBHttp  *m_http;

    void didClickedBtn();
    void didClickedThreadBtn();

};
#endif // HBHTTPWGT_H
