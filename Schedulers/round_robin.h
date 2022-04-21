#pragma once
#include "process.h"
#include "node.h"
#include "linkedlist.h"
#include <string>
using namespace std;

class round_robin {
private:
    int size;
    Process** process;
    int q = 0; //Time Quantum

public:

    round_robin(Process* processes[], int n, int quan);
    void gantt_chart();
    double waiting_time();
    double turnarround_time();
};
