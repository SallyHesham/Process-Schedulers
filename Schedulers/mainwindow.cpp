#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "process.h"
#include "linkedlist.h"
#include "node.h"
#include "fcfs.h"
#include "Priority.h"

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
    Process *arr[num_of_processes];
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
    LinkedList list;

    if (selected_scheduler == "First Come First Serve"){
        fcfs* scheduler = new fcfs(arr, num_of_processes);
        list = scheduler->gantt_chart();

    } else if (selected_scheduler == "Round Robin"){

    } else if (selected_scheduler == "Priority (preemptive)"){

    } else if (selected_scheduler == "Priority (non-preemptive)"){
        Priority* scheduler = new Priority(arr, num_of_processes);
        list = scheduler->gantt_chart();

    } else if (selected_scheduler == "Shortest Job First (preemptive)"){

    } else if (selected_scheduler == "Shortest Job First (non-preemptive)"){

    } else {QApplication::quit();}

    //for testing
    //list.add_node(1, 0, 2);
    //list.add_node(2, 2, 5);
    //end testing
    Node* node = list.get_head();
    int num_of_slots = 0;
    while(node != nullptr){
        num_of_slots++;
        node = node->get_next();
    }
    node = list.get_head();

    ui->horizontalLayout_5->addWidget(new QLabel(QString::number(0)));
    for(int slot = 0; slot < num_of_slots; slot++){
        int dur = node->get_end() - node->get_start();
        //ui->horizontalLayout_3->addWidget(, dur);
        ui->horizontalLayout_5->addStretch(dur);
        ui->horizontalLayout_5->addWidget(new QLabel(QString::number(node->get_end())));
        node = node->get_next();
    }
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_buttonBox_3_rejected()
{

    QApplication::quit();
}

