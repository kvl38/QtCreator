#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>
#include<QtSql/QSqlDatabase>
#include<QSqlQuery>
#include <QTime>
#include <QDate>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include<QSystemTrayIcon>
#include <QtGui/QIcon>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("message.db");

    if(!db.open())
        qDebug()<<"db didn't open";

    if (!_socket.bind(QHostAddress::Any,5566))
        qDebug()<< "network error";

    connect(&_socket, &QUdpSocket::readyRead, this, &MainWindow::getData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getData()
{
    while (_socket.hasPendingDatagrams())
    {
    QNetworkDatagram datagram = _socket.receiveDatagram();

    const QByteArray data = datagram.data();
    qDebug() << data;

    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QSqlQuery query(db);
    bool prep = query.prepare(QString("insert into message values(?,?,?)"));
    if (!prep)
        qDebug()<<"error";

    query.addBindValue(QString(data));
    query.addBindValue(date.toString());
    query.addBindValue(time.toString());
    query.exec();

    QMessageBox::information(this, "You entered", QString(data));
    }
}













    //    mSystemTrayIcon = new QSystemTrayIcon(this);
//    mSystemTrayIcon->setIcon(QIcon(":/myappico.png.png"));
//    mSystemTrayIcon->setVisible(true);

//    mSystemTrayIcon->showMessage("Message", "...");

//    qDebug()<<"end";



//void MainWindow::on_send_clicked()
//{
//    mSystemTrayIcon = new QSystemTrayIcon(this);
//    mSystemTrayIcon->setIcon(QIcon(":/myappico.png.png"));
//    mSystemTrayIcon->setVisible(true);
//    mSystemTrayIcon->showMessage("Hello", "Hello world");

//    qDebug()<<"end";
//}



//void MainWindow::on_send_clicked()
//{
//    QDate date = QDate::currentDate();
//    QTime time = QTime::currentTime();

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("message.db");

//    if(!db.open())
//        qCritical()<<"db didn't open";

//    QSqlQuery query(db);
//    bool ok = query.prepare(QString("insert into message values(?,?,?)"));
//    if (!ok)
//        qDebug()<<"error";
//    QString message = ui->lineEdit->text();
//    query.addBindValue(message);
//    query.addBindValue(date.toString());
//    query.addBindValue(time.toString());
//    query.exec();
//    ui->lineEdit->clear();
//}


