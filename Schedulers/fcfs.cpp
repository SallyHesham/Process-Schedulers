#include "fcfs.h"
   
fcfs::fcfs (Process processes [] , int n)
{
        for (int i =0 ; i <= n-1;i++)
        {
            process[i] = processes[i];
            }
            size = n-1;
}
        
        
LinkedList fcfs::gantt_chart() 
{
        LinkedList gantt (process[0].get_name(),process[0].get_entry(),process[0].get_burst());
        int count = process[0].get_entry() + process[0].get_burst();
        for (int i = 1 ; i <= size ; i++){
            count += process[i].get_burst();
            gantt.add_node (process[i].get_name(),count-process[i].get_burst(), count);
            }
            return gantt;
}
    
    
double fcfs::waiting_time ()
{
        double count = process[0].get_entry() + process[0].get_burst();
        double waiting = 0.0;
        for (int i = 1; i <=size ; i++){
            waiting +=count - process[i].get_entry();
            count += process[i].get_burst();
            }
        return (waiting/size);
}
    
    
    
double fcfs::turnarround_time()
{
     double count = process[0].get_entry() + process[0].get_burst();
     double turnarround =  process[0].get_burst() - process [0].get_entry();
     for (int i = 1; i <=size ; i++){
        count += process[i].get_burst();
        turnarround += count - process[i].get_entry();
     }
     return (turnarround/size);
}
