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

        connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
        connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
        connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
        connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

        ui->pushButton_plus->setCheckable(true);
        ui->pushButton_minus->setCheckable(true);
        ui->pushButton_multiply->setCheckable(true);
        ui->pushButton_divide->setCheckable(true);

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

        if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked() ||
                ui->pushButton_divide->isChecked()) && (!userISTypingNum))
        {
            labelNumber = button->text().toDouble();
            userISTypingNum = true;
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();
        }
    //    labelNumber = (ui->label->text() + button->text()).toDouble();
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }




void MainWindow::on_pushButton_clear_released()
    {
         ui->pushButton_plus->setChecked(false);
         ui->pushButton_minus->setChecked(false);
         ui->pushButton_multiply->setChecked(false);
         ui->pushButton_divide->setChecked(false);


         userISTypingNum = false;

         ui->label->setText("0");
   }

void MainWindow::on_pushButton_equal_released()
   {

    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

   if(ui->pushButton_plus->isChecked())
   {
       labelNumber = firstNum + secondNum;
       newLabel = QString::number(labelNumber,'g',15);
       ui->label->setText(newLabel);
       ui->pushButton_plus->setChecked(false);
   }
   else if(ui->pushButton_minus->isChecked())
   {
       labelNumber = firstNum - secondNum;
       newLabel = QString::number(labelNumber,'g',15);
       ui->label->setText(newLabel);
       ui->pushButton_minus->setChecked(false);
   }
   else if(ui->pushButton_multiply->isChecked())
   {
       labelNumber = firstNum * secondNum;
       newLabel = QString::number(labelNumber,'g',15);
       ui->label->setText(newLabel);
       ui->pushButton_multiply->setChecked(false);
   }
   else if(ui->pushButton_divide->isChecked())
   {
       labelNumber = firstNum / secondNum;
       newLabel = QString::number(labelNumber,'g',15);
       ui->label->setText(newLabel);
       ui->pushButton_divide->setChecked(false);
   }
        userISTypingNum = false;
}




void MainWindow::binary_operation_pressed()
   {
        QPushButton *button = (QPushButton*)sender();

        firstNum = ui->label->text().toDouble();
        button->setChecked(true);
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
