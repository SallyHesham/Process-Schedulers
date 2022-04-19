#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include <string>
#include "log.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString selected_scheduler;
    int num_of_processes;
    int quantum;
    void draw(list<Log*> log);

private slots:

    void on_buttonBox_accepted();


    void on_buttonBox_2_accepted();

    void on_buttonBox_3_rejected();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
