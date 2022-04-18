#include "round_robin.h"

round_robin::round_robin(Process* processes[], int n, int quan)
{
    process = processes;
    size = n-1;
    q = quan;
}


LinkedList round_robin::gantt_chart()
{
    LinkedList gantt; // need empty constructor
    int count = 0;
    int done = 0;

    while (done < size) {
        for (int i = 0; i < size; i++) {
            if (process[i]->get_time_left() - q > 0) {
                count += q;
                gantt.add_node(process[i]->get_name(), count - q, count);
                process[i]->set_time_left(process[i]->get_time_left() - q);
            }

            else {
                count += process[i]->get_time_left();
                gantt.add_node(process[i]->get_name(), count - process[i]->get_time_left(), count);
                process[i]->set_time_left(0);
                process[i]->set_end_time(count); // please add set_end_time and get_end_time
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
        waiting += process[i]->get_end_time() - process[i]->get_burst(); // needs get_end_time
    }
    return (waiting / size);
}



double round_robin::turnarround_time()
{
    double turnarround = 0.0;
    for (int i = 0; i < size; i++) {
        turnarround += process[i]->get_end_time();
    }
    return (turnarround / size);
}
