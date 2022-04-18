#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(int name , int s , int e)
{
     Node* node = new Node(name, s, e);
     this->head = node;
     this->tail = node;
}

void LinkedList::add_node(int n, int s, int e)
{
    Node* node = new Node(n, s, e);
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
