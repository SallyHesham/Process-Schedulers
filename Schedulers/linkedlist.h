#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"

class LinkedList
{
private:
    Node* head;
    Node* tail;
public:
    LinkedList();
    void add_node(int s, int e);
    Node* get_head();
    Node* get_tail();
};

#endif // LINKEDLIST_H
