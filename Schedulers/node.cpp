#include "node.h"

Node::Node(int s, int e)
{
    start = s;
    end = e;
}

void Node::set_next(Node *n)
{
    next = n;
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
