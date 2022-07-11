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

}
