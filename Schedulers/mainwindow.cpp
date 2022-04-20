#include "mainwindow.h"
#include "scheduler.h"
#include "processf.h"
#include "ui_mainwindow.h"
#include "process.h"
#include "linkedlist.h"
#include "node.h"
#include "fcfs.h"
#include "Priority.h"
#include "round_robin.h"
#include "vec.h"

vector <int> vn;
vector <double> vs;
vector <double> ve;
double wt;

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

     list<processf*> processes;

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
            processf* pr = new processf(arr[row]->get_name(), e, b, p);
                    processes.push_back(pr);
        }
        else{
            arr[row] = new Process(e, b);
            processf* pr = new processf(arr[row]->get_name(), e, b, b);
                    processes.push_back(pr);
        }
    }

    Scheduler* schedulerf = new Scheduler(processes);

    LinkedList list;
    double awt = 0;
    bool jump = true;

    if (selected_scheduler == "First Come First Serve"){
        fcfs* scheduler = new fcfs(arr, num_of_processes);
        list = scheduler->gantt_chart();
        //awt = scheduler->waiting_time();
        jump = false;

    } else if (selected_scheduler == "Round Robin"){
        round_robin* scheduler = new round_robin(arr, num_of_processes, quantum);
        list = scheduler->gantt_chart();
        //awt = scheduler->waiting_time();
        jump = false;

    } else if (selected_scheduler == "Priority (preemptive)"){
        schedulerf->priority(true, false);

    } else if (selected_scheduler == "Priority (non-preemptive)"){
       schedulerf->priority(false, false);
       //MainWindow::draw(schedulerf->getLog());
        //delete schedulerf;
       //return;

    } else if (selected_scheduler == "Shortest Job First (preemptive)"){
        schedulerf->priority(true, true);

    } else if (selected_scheduler == "Shortest Job First (non-preemptive)"){
        schedulerf->priority(false, true);

    } else {QApplication::quit();}

    //for testing
    //list.add_node(1, 0, 2);
    //list.add_node(2, 2, 5);
    //end testing
    if(!jump){
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

            QLabel* pLabel = new QLabel("P"+QString::number(node->get_name()));
            pLabel->setStyleSheet("QLabel { background-color : cyan; color : black; }");
            pLabel->setAlignment(Qt::AlignCenter);
            ui->horizontalLayout_3->addWidget(pLabel, dur);

            ui->horizontalLayout_5->addStretch(dur);
            ui->horizontalLayout_5->addWidget(new QLabel(QString::number(node->get_end())));
            node = node->get_next();
        }
        awt = Process::awt(list, num_of_processes);
        ui->label_5->setText("Average Waiting Time: "+QString::number(awt));
        ui->stackedWidget->setCurrentIndex(2);
    }
    else{

        int num_of_slots = vn.size();


        ui->horizontalLayout_5->addWidget(new QLabel(QString::number(0)));
        for(int slot = 0; slot < num_of_slots; slot++){
            int dur = ve[slot] - vs[slot];
            //ui->horizontalLayout_3->addWidget(, dur);

            QLabel* pLabel = new QLabel("P"+QString::number(vn[slot]));
            pLabel->setStyleSheet("QLabel { background-color : cyan; color : black; }");
            pLabel->setAlignment(Qt::AlignCenter);
            ui->horizontalLayout_3->addWidget(pLabel, dur);

            ui->horizontalLayout_5->addStretch(dur);
            ui->horizontalLayout_5->addWidget(new QLabel(QString::number(ve[slot])));
        }
        //awt = Process::awt(list, num_of_processes);
        ui->label_5->setText("Average Waiting Time: "+QString::number(wt/num_of_processes));
        ui->stackedWidget->setCurrentIndex(2);
    }
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_buttonBox_3_rejected()
{

    QApplication::quit();
}

