#include "linkedlist.h"

LinkedList::LinkedList()
{

}

void LinkedList::add_node(int s, int e)
{
    Node* node = new Node(s, e);
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
