#include "fcfs.h"
#include "vec.h"
#include <functional>

 void swap(Process * &a, Process * &b)
{
   /* Process temp = a;
    a = b;
    b = temp;*/
    
    std::swap(a,b);
}


void arrsort (Process *processes[] , int size){
    
    for (int iter = 0 ; iter < size-1 ; iter++){
        bool swapped = false;
    for (int i = 0 ; i < size-1-iter ;i++ ){
        if (processes[i]->get_entry() > processes[i+1]->get_entry()){
        swap(processes[i],processes[i+1]);
            swapped = true;
            }
        if (!swapped){
            return;
            }
        }
                } 
    
    }

fcfs::fcfs (Process *processes[] , int n)
{
    process = processes;
/*
        for (int i =0 ; i <= n-1;i++)
        {
            process[i] = processes[i];
            }*/
            size = n-1;
      arrsort(process,size+1);
}


void fcfs::gantt_chart()
{
        //LinkedList gantt (process[0]->get_name(),process[0]->get_entry(),process[0]->get_burst(), process[0]->get_entry(), process[0]->get_burst());
        vn.push_back(process[0]->get_name());
        vs.push_back(process[0]->get_entry());
        ve.push_back(process[0]->get_burst());
        va.push_back(process[0]->get_entry());
        vb.push_back(process[0]->get_burst());
        int count = process[0]->get_entry() + process[0]->get_burst();
        for (int i = 1 ; i <= size ; i++){
            count += process[i]->get_burst();
            //gantt.add_node (process[i]->get_name(),count-process[i]->get_burst(), count, process[i]->get_entry(), process[i]->get_burst());
            vn.push_back(process[i]->get_name());
            vs.push_back(count-process[i]->get_burst());
            ve.push_back(count);
            va.push_back(process[i]->get_entry());
            vb.push_back(process[i]->get_burst());
        }
           // return gantt;
}


double fcfs::waiting_time ()
{
        double count = process[0]->get_entry() + process[0]->get_burst();
        double waiting = 0.0;
        for (int i = 1; i <=size ; i++){
            waiting +=count - process[i]->get_entry();
            count += process[i]->get_burst();
            }
        return (waiting/size+1);
}



double fcfs::turnarround_time()
{
     double count = process[0]->get_entry() + process[0]->get_burst();
     double turnarround =  process[0]->get_burst() - process [0]->get_entry();
     for (int i = 1; i <=size ; i++){
        count += process[i]->get_burst();
        turnarround += count - process[i]->get_entry();
     }
     return (turnarround/size);
}
