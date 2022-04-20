#include "node.h"

Node::Node(int n, int s, int e, int a, int b)
{
    name = n;
    start = s;
    end = e;
    next = nullptr;
    entry = a;
    burst = b;
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

int Node::get_burst()
{
    return burst;
}
