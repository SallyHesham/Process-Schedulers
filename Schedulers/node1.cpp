#include "node1.h"


node::node (string name , int start_time , int end_time)
{
    process_name = name;
    start = start_time;
    end = end_time;
    next = NULL;

}

node::node (string name)
{
    process_name = name;
    next = NULL;
}

int node :: getstart()
{
    return start;
}

void node:: setstart(int s) 
{
    start=s;
}

int node:: getend()
{
    return end;
}

    
void node::setend(int e)
{
    end=e;
}
    
node * node :: getNext() 
{
    return next;
}
    
    
void node :: setNext( node * n)
 {
    next =n;
}
