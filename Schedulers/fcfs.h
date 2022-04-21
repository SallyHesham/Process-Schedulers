#ifndef FCFS_H
#define FCFS_H
#include "process.h"
#include "node.h"
#include "linkedlist.h"
// #include <string>
// using namespace std;

class fcfs {
private:
    int size;
    Process** process;
   
   
public:
    
    fcfs (Process *processes[], int n);
    void gantt_chart();
    double waiting_time ();
    double turnarround_time();
    };

#endif // FCFS_H
