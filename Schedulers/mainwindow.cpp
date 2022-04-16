#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "process.h"


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
        c = 2;
        hl = {"Entry Time", "Burst Time"};
        ui->label_4->setEnabled(true);
        ui->spinBox_2->setEnabled(true);
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
    //ui->tableWidget->setItemDelegate(QAbstractItemDelegate(new QLineEdit(new QIntValidator(0, 9))));
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_buttonBox_2_accepted()
{
    Process* arr[num_of_processes];
    quantum = ui->spinBox_2->value();
    int e = 0; int b = 0; int p = 0;

    for(int row = 0; row < num_of_processes; row ++){

        for(int col = 0; col < ui->tableWidget->columnCount(); col++){
            switch(col){
            case 0:
                e = ui->tableWidget->item(row, col)->text().toInt();
                break;
            case 1:
                b = ui->tableWidget->item(row, col)->text().toInt();
                break;
            case 2:
                p = ui->tableWidget->item(row, col)->text().toInt();
                break;
            }
        }

        if(ui->tableWidget->columnCount() == 3){
            arr[row] = new Process(e, b, p);
        }
        else{
            arr[row] = new Process(e, b);
        }
    }

    ui->stackedWidget->setCurrentIndex(2);
}

