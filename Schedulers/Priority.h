#ifndef PROCESS_PRIORITY_H
#define PROCESS_PRIORITY_H
#include "process.h"
#include "node.h"
#include "linkedlist.h"


class Priority {
private:
    Process **p;
    LinkedList chart;
    int size;

public:
    Priority(Process* x[],int n);
    LinkedList gantt_chart();

};


#endif //PROCESS_PRIORITY_H
