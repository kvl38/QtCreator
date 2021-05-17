#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_file_clicked()
{
    scene->clear();
    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose File"));
    QFile file(fileName);
    QStringList list_start;

    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
            list_start << file.readLine();
        }
        file.close();
    }

    int k = 0;
    int height = 0;
    int width = 0;
    for (int i=0; i<list_start.length(); i++)
    {
        QStringList tempList = list_start[i].split(" ");
        while(k!=tempList.length()-1)
            {
                scene->addRect(QRectF(0+width, 0+height, 100, 30));
                QGraphicsTextItem *text = scene->addText(tempList[k]);
                text->setDefaultTextColor(QColor(Qt::red));
                text->setFont(QFont("Courier New" , 13));
                text->setPos(0+width,0+height);

                text->boundingRect();
                text->pos();


                if (k == 0 && i != list_start.length()-1)
                {
                    scene->addLine(50,30+height,50,80+height);
                }

                if (k != tempList.length()-2)
                {
                    scene->addLine(100+width,15+height,150+width,15+height);
                }

                width+=150;
                k++;
            }

        height+=80;
        k = 0;
        width = 0;
    }
}













//void MainWindow::on_open_file_clicked()
//{
//    scene->clear();
//    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose File"));
//    QFile file(fileName);
//    QStringList list_start;

//    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
//    {
//        while(!file.atEnd())
//        {
//            list_start << file.readLine();
//        }
//        file.close();
//    }

//    int k = 0;
//    int height = 0;
//    int width = 0;
//    for (int i=0; i<list_start.length(); i++)
//    {
//        QStringList tempList = list_start[i].split(" ");
//        while(k!=tempList.length()-1)
//            {
//                scene->addRect(QRectF(0+width, 0+height, 100, 30));
//                QGraphicsTextItem *text = scene->addText(tempList[k]);
//                text->setDefaultTextColor(QColor(Qt::red));
//                text->setFont(QFont("Courier New" , 13));
//                text->setPos(0+width,0+height);

//                text->boundingRect();
//                text->pos();


//                if (k == 0 && i != list_start.length()-1)
//                {
//                    scene->addLine(50,30+height,50,80+height);
//                }

//                if (k != tempList.length()-2)
//                {
//                    scene->addLine(100+width,15+height,150+width,15+height);
//                }

//                width+=150;
//                k++;
//            }

//        height+=80;
//        k = 0;
//        width = 0;
//    }
//}
