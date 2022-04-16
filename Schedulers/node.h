#ifndef NODE_H
#define NODE_H
//#include <string>
//using namespace std;

class Node
{
public:
    //string name;
    int start;
    int end;
    Node* next;
public:
    Node(int s, int e);
    void set_next(Node* n);
    int get_start();
    int get_end();
    Node* get_next();
};

#endif // NODE_H
