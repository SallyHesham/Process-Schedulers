#include "process.h"

int Process::num = 0;

int Process::get_num()
{
    num++;
    return num;
}

Process::Process(int e, int b)
{
    entry = e;
    burst = b;
    time_left = b;
    priority = b;
    name = "P" + to_string(get_num());
}

Process::Process(int e, int b, int p)
{
    entry = e;
    burst = b;
    time_left = b;
    priority = p;
    name = "P" + to_string(get_num());
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

string Process::get_name()
{
    return name;
}
