#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QDebug>
#include<QList>
#include <QXmlStreamAttribute>
#include<QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_clicked();

    void on_add_clicked();

    void on_save_clicked();

    void on_remove_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QList<QString>list_start;
};
#endif // MAINWINDOW_H
