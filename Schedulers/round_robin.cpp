#include "round_robin.h"

round_robin::round_robin(Process processes[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        process[i] = processes[i];
    }
    size = n - 1;
}


list round_robin::gantt_chart()
{
    list gantt(); // need empty constructor 
    int count = 0;
    int done = 0;
    
    for (int i = 0; i < size; i++) {
        process[i].set_time_left = process[i].get_burst;
    }

    while (done < size) {
        for (int i = 0; i < size; i++) {
            if (process[i].get_time_left - q > 0) {
                count += q;
                gantt.add(process[i].get_name(), count - q, count);
                process[i].set_time_left = process[i].get_time_left - q;
            }

            else {
                count += process[i].get_time_left;
                gantt.add(process[i].get_name(), count - process[i].get_time_left, count);
                process[i].set_time_left = 0;
                process[i].set_end_time = count; // please add set_end_time and get_end_time
                done++;
            }
        }
    }
    
    return gantt;
}


double round_robin::waiting_time()
{
    double waiting = 0.0;
    for (int i = 0; i < size; i++) {
        waiting += process[i].get_end_time() - process[i].get_burst(); // needs get_end_time
    }
    return (waiting / size);
}



double round_robin::turnarround_time()
{
    double turnarround = 0.0;
    for (int i = 0; i < size; i++) {
        turnarround += process[i].get_end_time();
    }
    return (turnarround / size);
}

