#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(int name , int s , int e, int a)
{
     Node* node = new Node(name, s, e, a);
     this->head = node;
     this->tail = node;
}

void LinkedList::add_node(int n, int s, int e, int a)
{
    Node* node = new Node(n, s, e, a);
    if (!this->head) {
        this->head = node;
    }
    else {
        this->tail->set_next(node);
    }

    this->tail = node;

}

Node *LinkedList::get_head()
{
    return head;
}

Node *LinkedList::get_tail()
{
    return tail;
}
