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
    LinkedList(int name , int s , int e, int a, int b);
    void add_node(int n, int s, int e, int a, int b);
    Node* get_head();
    Node* get_tail();
};

#endif // LINKEDLIST_H
