#include "scheduler.h"

 void Scheduler::sortPriority()
 {
    _queue.sort([&](processf* & lhs, processf* & rhs) {
        double t1 = lhs->getArrivalTime();
        double t2 = rhs->getArrivalTime();
        if (current_time >= t1 && current_time >= t2)
            return lhs->getPriority() <= rhs->getPriority();
        if (t1 < t2)
            return true;
        else if (t1 == t2)
            return lhs->getPriority() <= rhs->getPriority();
        else
            return false;
    });
 };

void Scheduler::priority(bool prempt, bool sjf) {
    double totalWaiting = 0;

    sortPriority();
    processf* top = _queue.front();
    if (prempt)
    {

        while(_queue.size() != 0) {
            if (top->getRemainingTime(current_time) <= 0)
            {
                stop(top);
                totalWaiting += top->getWaitingTime();
                delete top;
                _queue.pop_front();
                top = _queue.front();
                if (_queue.size() == 0) break;
            }

            sortPriority();
            if (_queue.front() != top)
            {
                stop(top);
                if(sjf == true){top->setPriority(top->getRemainingTime(current_time));}
                top = _queue.front();
            }

            if (!top->isWorking() && top->getArrivalTime() <= current_time && top->getRemainingTime(current_time) > 0) {
                start(top);
            }

            current_time++;
        }
    }
    else {
            while(_queue.size() > 0) {
            if(top->getArrivalTime() <= current_time) {
                sortPriority();
                top = _queue.front();
                double latency = top->getBurstTime();
                start(top);
                current_time += latency;
                stop(top);
                totalWaiting += top->getWaitingTime();
                delete top;
                _queue.pop_front();
            }
            else current_time++;
        }
    }

    //cout << "Total time: " << current_time;
    //cout << "Average waiting time: " << totalWaiting/_queue.size();
    wt = totalWaiting;
}
