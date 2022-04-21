#include "process.h"
#include "vec.h"

//int Process::num = 0;

int Process::get_num()
{
    static int num = 0;
    num++;
    return num;
}

Process::Process(int e, int b)
{
    entry = e;
    burst = b;
    time_left = b;
    priority = b;
    name = get_num();
}

Process::Process(int e, int b, int p)
{
    entry = e;
    burst = b;
    time_left = b;
    priority = p;
    name = get_num();
}

void Process::set_time_left(int x)
{
    time_left = x;
}

void Process::update_priority(int p)
{
    priority = p;
}

int Process::get_entry()
{
 return entry;
}

int Process::get_burst()
{
    return burst;
}

int Process::get_priority()
{
    return priority;
}

int Process::get_time_left()
{
    return time_left;
}

int Process::get_name()
{
    return name;
}

int Process::get_end_time()
{
    return end_time;
}

void Process::set_end_time(int t)
{
    end_time = t;
}

double Process::awt(LinkedList list, int n)
{
    int arr[n];
    double res = 0;
    for(int i = 0; i <= n; i++){
        arr[i] = -1;
    }
    int index = 0;
    Node* node = list.get_head();
    while(node != nullptr){
        index = node->get_name();

        arr[index] = node->get_end() - node->get_entry() - node->get_burst();

        node = node->get_next();
    }
    for(int i = 1; i <= n; i++){
        res += arr[i];
    }
    return(res/n);
}

double Process::awt(int n)
{
    int arr[n];
    double res = 0;
    for(int i = 0; i <= n; i++){
        arr[i] = -1;
    }
    int index = 0;

    for(int i = 0; i < (int)vn.size(); i++){
        index = vn[i];

        arr[index] = ve[i] - va[i] - vb[i];
    }
    for(int i = 1; i <= n; i++){
        res += arr[i];
    }
    return(res/n);
}
