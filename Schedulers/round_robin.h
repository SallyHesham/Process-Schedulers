#pragma once
#include "process.h"
#include "node1.h"
#include "list.h"
#include <string>
using namespace std;

class round_robin {
private:
    int size;
    Process* process;
    int q = 4; //Time Quantum

public:

    round_robin(Process processes[], int n);
    list gantt_chart();
    double waiting_time();
    double turnarround_time();
};
