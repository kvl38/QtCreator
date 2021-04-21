#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose File"));
    QFile xml_file(fileName);
    ui->lineEdit_4->setText(fileName);

    if(!xml_file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"error";
    }

    QXmlStreamReader read;
    read.setDevice(&xml_file);
    read.readNext();

    while(!read.atEnd())
    {

            foreach(const QXmlStreamAttribute &attr, read.attributes())
            {
                if(attr.name().toString() == "name")
                {
                    qDebug()<<attr.value().toString();
                    list_start.append(attr.value().toString());

                }
                if(attr.name().toString() == "surname")
                {
                    qDebug()<<attr.value().toString();
                    list_start.append(attr.value().toString());
                }
                if(attr.name().toString() == "age")
                {
                    qDebug()<<attr.value().toString();
                    list_start.append(attr.value().toString());
                }
            }

        read.readNext();
        if(read.hasError())
        {
            qDebug()<<read.errorString();
        }
    }

    model = new QStandardItemModel(ui->tableView);
    model->setHorizontalHeaderLabels(QStringList() << "name" << "surname" << "age");


    for (int i = 0; i < list_start.length(); i+=3)
        {
            QList<QStandardItem *> items;
            items.append(new QStandardItem(list_start[i]));
            items.append(new QStandardItem(list_start[i+1]));
            items.append(new QStandardItem(list_start[i+2]));
            model->appendRow(items);
        }

    ui->tableView->setModel(model);

    xml_file.close();


}

void MainWindow::on_add_clicked()
{
    list_start.append(ui->lineEdit->text());
    list_start.append(ui->lineEdit_2->text());
    list_start.append(ui->lineEdit_3->text());

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}


void MainWindow::on_save_clicked()
{
    model->clear();
    model->setHorizontalHeaderLabels(QStringList() << "name" << "surname" << "age");

    QFile xml_file(ui->lineEdit_4->text());
    xml_file.open(QIODevice::WriteOnly);
    QXmlStreamWriter writer(&xml_file);

    writer.writeStartDocument();
    writer.setAutoFormatting(true);

    writer.writeStartElement("users");

    for(int k=0; k<list_start.length(); k+=3)
    {
        writer.writeStartElement("user");
        writer.writeAttribute("name", list_start[k]);
        writer.writeAttribute("surname", list_start[k+1]);
        writer.writeAttribute("age", list_start[k+2]);
        writer.writeEndElement();
    }

    writer.writeEndElement();
    writer.writeEndDocument();
    xml_file.close();



    for (int i = 0; i < list_start.length(); i+=3)
        {
            QList<QStandardItem *> items;
            items.append(new QStandardItem(list_start[i]));
            items.append(new QStandardItem(list_start[i+1]));
            items.append(new QStandardItem(list_start[i+2]));
            model->appendRow(items);
        }

    ui->tableView->setModel(model);
}

void MainWindow::on_remove_clicked()
{
    QString name = ui->lineEdit->text();
    QString surname = ui->lineEdit_2->text();
    QString age = ui->lineEdit_3->text();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();

    for(int i=0; i<list_start.length(); i++)
    {
        if(list_start[i] == name)
        {
            if(list_start[i+1] == surname)
            {
                if(list_start[i+2] == age)
                {
                    list_start.removeAt(i+2);
                    list_start.removeAt(i+1);
                    list_start.removeAt(i);
                    break;
                }
            }
        }
    }



}
