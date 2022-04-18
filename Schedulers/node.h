#ifndef NODE_H
#define NODE_H
//#include <string>
//using namespace std;

class Node
{
public:
    int name;
    int start;
    int end;
    int entry;
    Node* next;
public:
    Node(int n, int s, int e, int a);
    void set_next(Node* n);
    int get_name();
    int get_start();
    int get_end();
    Node* get_next();
    int get_entry();
};

#endif // NODE_H
