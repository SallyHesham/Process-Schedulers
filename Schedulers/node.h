#ifndef NODE_H
#define NODE_H
//#include <string>
//using namespace std;

class Node
{
private:
    int name;
    int start;
    int end;
    int entry;
    int burst;
    Node* next;
public:
    Node(int n, int s, int e, int a, int b);
    void set_next(Node* n);
    int get_name();
    int get_start();
    int get_end();
    Node* get_next();
    int get_entry();
    int get_burst();
};

#endif // NODE_H
