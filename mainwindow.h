#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QUdpSocket>
#include"notification.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void getData();

//    void on_send_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket _socket;
    QSqlDatabase db;
    Notification *notif;
//    QSystemTrayIcon *mSystemTrayIcon;

};
#endif // MAINWINDOW_H
