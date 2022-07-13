#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

QString firstNum, secondNum;
QString plusLabel;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));


    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_add->setCheckable(true);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
//    qDebug()<<"test";




      if(ui->pushButton_add->isChecked())
      {
           QPushButton *button = (QPushButton*)sender();
           ui->label->setText(firstNum +plusLabel + button->text());
      }
      else
      {
          QPushButton *button = (QPushButton*)sender();
          double labelNumber;
          QString newLabel;
          labelNumber = (ui->label->text() + button->text()).toDouble();
          newLabel = QString::number(labelNumber);
          ui->label->setText(newLabel);
      }
}

void MainWindow::binary_operation_pressed()
{
 //qDebug()<<"test";

    QPushButton *button = (QPushButton*)sender();
    firstNum = ui->label->text();


    plusLabel = button->text();
    ui->label->setText(firstNum+plusLabel);
//    button->setChecked(false);

}
