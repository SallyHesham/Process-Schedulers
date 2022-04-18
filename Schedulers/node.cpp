#include "node.h"

Node::Node(int n, int s, int e, int a)
{
    name = n;
    start = s;
    end = e;
    next = nullptr;
    entry = a;
}

void Node::set_next(Node *n)
{
    next = n;
}

int Node::get_name()
{
    return name;
}

int Node::get_start()
{
    return start;
}

int Node::get_end()
{
    return end;
}

Node *Node::get_next()
{
    return next;
}

int Node::get_entry()
{
    return entry;
}
