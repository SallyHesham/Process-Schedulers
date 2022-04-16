#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include <string>
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

private slots:

    void on_buttonBox_accepted();


    void on_buttonBox_2_accepted();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
