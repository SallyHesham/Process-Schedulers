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
    QStringList hl;
    QStringList vl;
    if ((selected_scheduler == "Priority (preemptive)") || (selected_scheduler == "Priority (non-preemptive)")) {
        c = 3;
        hl = {"Entry Time", "Burst Time", "Priority"};
    }
    else if ((selected_scheduler == "Round Robin")){
        c = 3;
        hl = {"Entry Time", "Burst Time", "Quantum"};
    }
    else {
        c = 2;
        hl = {"Entry Time", "Burst Time"};
    }
    for (int i = 1; i <= num_of_processes; i++){
        vl << "P" + QString::number(i);
    }
    ui->tableWidget->setColumnCount(c);
    ui->tableWidget->setHorizontalHeaderLabels(hl);
    ui->tableWidget->setVerticalHeaderLabels(vl);
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_buttonBox_2_accepted()
{
    ui->stackedWidget->setCurrentIndex(2);
}

