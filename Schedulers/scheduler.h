#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <list>
#include "processf.h"
#include "log.h"
#include <queue>
#include <map>
#include <time.h>

class Scheduler
{

private:
    size_t current_time;
    size_t logStartTime;
    list<processf*> _queue;
    list<Log*> log;
    map<size_t,string> colours;


    void sortSJF();
    void sortPriority();

    void start(processf* p) {
        p->start(current_time);

        if(colours[p->getPID()] == "") {
            //srand(time(NULL));
            string color = "rgb(" + to_string(rand()%255)+ "," + to_string(rand()%255) + "," + to_string(rand()%255) + ")";
            colours[p->getPID()] = color;
        }

        logStartTime = current_time;
    }

    void stop(processf* p) {
        p->stop(current_time);
        size_t pid = p->getPID();
        log.push_back(new class Log(pid,logStartTime, current_time, colours[pid]));
    }

public:
    Scheduler(list<processf*> queue) {
        _queue = queue;
        current_time = 0;
    }

    ~Scheduler() {
    }

    void sjf(bool prempt=false);
    void fcfs();
    void priority(bool prempt=false, bool sjf=false);
    void roundRobin(double quantum);

    list<Log*> getLog(){
        return log;
    }


};

#endif
