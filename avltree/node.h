#ifndef NODEHEADER
#define NODEHEADER
#include<iostream>
using namespace std;
class Node
{
    Node* Parent;
    Node* Left;
    Node* Right;
    int key;
    int l_height;
    int r_height;
    int balance_factor;
    public:
    Node();
    Node(int);
    ~Node();
    Node* getLeftChild();
    Node* getRightChild();
    Node* getParent();
    int getkey();
    int get_lheight();
    int get_rheight();
    int get_balance_factor();
    bool setLeftChild(Node*);
    bool setRightChild(Node*);
    bool setParent(Node*);
    bool setkey(int);
    bool set_lheight(int);
    bool set_rheight(int);
    bool set_balancefactor();

};
#endif // NODEHEADER
