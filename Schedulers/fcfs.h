#include "process.h"
#include "node1.h"
#include "list.h"
#include <string>
using namespace std;

class fcfs {
private:
    int size;
    Process *process  ;
   
   
public:
    
    fcfs (Process processes [] , int n);
    list gantt_chart();
    double waiting_time ();
    double turnarround_time();
    };

#endif // FCFS_H
