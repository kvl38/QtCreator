#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QUdpSocket>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_send_clicked()
{
    QUdpSocket socket;
    socket.writeDatagram(ui->lineEdit->text().toLatin1(), QHostAddress::Broadcast,5566);
    ui->lineEdit->clear();
}
