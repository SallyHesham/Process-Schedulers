#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_buttonBox_accepted()
{
    num_of_processes = ui->spinBox->value();
    selected_scheduler = ui->listWidget->currentItem()->text();//.toStdString();
    ui->tableWidget->setRowCount(num_of_processes);
    int c;
    if ((selected_scheduler == "Priority (preemptive)") || (selected_scheduler == "Priority (non-preemptive)")) {c = 3;}
    else {c = 2;}
    ui->tableWidget->setColumnCount(c);
    ui->stackedWidget->setCurrentIndex(1);
}

