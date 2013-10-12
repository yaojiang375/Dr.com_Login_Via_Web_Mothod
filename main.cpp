#include <QCoreApplication>
#include "WebLogin.h"
#include <QString>
#include <QList>
#include <QDebug>
#include <iostream>
#include <QtNetwork/QHttpRequestHeader>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString  mnd5,adress;
    QUrl                   url;
    url=QUrl("172.16.10.3");//青科大校园网服务器地址，其他学校直接替换QUrl内的IP地址即可（也支持网址）
    QString ID="m900224873";//账号
    QString Pass="123456";//密码

    QString pid="1";
    QString calg="12345678";
    QString tmpchar     = pid+Pass+calg;

    mnd5 = binl2hex(coreMD5(str2binl(tmpchar)));

    adress  =   "172.16.10.3";
    QByteArray             text;
    text.append("DDDDD="+ID+"&upass="+mnd5+calg+pid+"&R1=0&R2=1&para=00&0MKKey=123456");
    QNetworkRequest        request;

    request.setUrl(QUrl("http://172.16.10.3/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,text);
    QNetworkAccessManager tz;
    tz.post(request,text);
    qDebug()<<"Connected!";

    return a.exec();
}
