#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QDebug>

double firstNum;
bool userISTypingNum = false;

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

        connect(ui->pushButton_plus_minus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
        connect(ui->pushButton_percant,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
//    qDebug()<<"test";
    QPushButton *button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    labelNumber = (ui->label->text() + button->text()).toDouble();
    newLabel = QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_dot_released()
{
    ui->label->setText(ui->label->text()+".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if (button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);

    }
    if (button->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);

    }
}
