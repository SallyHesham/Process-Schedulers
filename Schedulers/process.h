#ifndef PROCESS_H
#define PROCESS_H
#include "linkedlist.h"
#include "node.h"
//#include <string>
//using namespace std;

class Process
{
private:
    int name;
    int entry;
    int burst;
    int priority;
    int time_left;
    //static int num;
    int get_num();
    int end_time;

public:
    Process(int e, int b);
    Process(int e, int b, int p);
    void set_time_left(int x);
    void update_priority(int p);
    int get_entry();
    int get_burst();
    int get_priority();
    int get_time_left();
    int get_name();
    int get_end_time();
    void set_end_time(int t);
    static double awt(LinkedList list, int n);
};


#endif // PROCESS_H
