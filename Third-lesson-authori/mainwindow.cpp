#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

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


void MainWindow::on_pushButton_clicked()
{
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (login == "admin" && password == "12345")
    {
        QMessageBox::information(this, "Authorization", "You have successfully logged in!");
    }
    else
    {
        QMessageBox::warning(this, "Authorization", "Login or password doesn't match");
    }
}
