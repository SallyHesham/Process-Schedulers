#ifndef PROCESS_H
#define PROCESS_H
#include <string>
using namespace std;

class Process
{
private:
    string name;
    int entry;
    int burst;
    int priority;
    int time_left;
    //static int num;
    int get_num();

public:
    Process(int e, int b);
    Process(int e, int b, int p);
    void set_time_left(int x);
    void update_priority(int p);
    int get_entry();
    int get_burst();
    int get_priority();
    int get_time_left();
    string get_name();
};


#endif // PROCESS_H
