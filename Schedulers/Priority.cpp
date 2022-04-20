
#include "Priority.h"
Priority::Priority(Process *x[], int n) {
    size=n;
    /*for(int i=0;i<size;i++){
        p[i]=x[i];
    }*/
    p = x;
}
LinkedList Priority::gantt_chart() {
    int is_completed[100];
    int current_time = 0;
    //int completed = 0;
  for(int i=0;i<size;i++){
        int idx = -1;
        int mx=100000;
        for(int i = 0; i < size; i++) {
            if(p[i]->get_entry()<=current_time && is_completed[i]==0){
                if(p[i]->get_priority()<mx){
                    mx=p[i]->get_priority();
                    idx=i;
                }
                if(p[i]->get_priority()==mx){
                    if(p[i]->get_entry()<p[idx]->get_entry()){
                        mx=p[i]->get_priority();
                        idx=i;
                    }
                }
            }
        }
        if (idx!=-1){
            int endtime=current_time+p[idx]->get_burst();
            chart.add_node(p[idx]->get_name(),current_time,endtime, p[idx]->get_entry(), p[idx]->get_burst());
            is_completed[idx] = 1;
            current_time=endtime;
        }
        else{
            current_time++;
        }
    }
    return chart;
}
