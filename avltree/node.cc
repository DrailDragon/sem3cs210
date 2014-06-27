#include "node.h"
Node::Node()
{
    Parent=NULL;
    Left=NULL;
    Right=NULL;
    key=0;
    l_height=0;
    r_height=0;
    balance_factor=0;
}
Node::Node(int a)
{
    Parent=NULL;
    Left=NULL;
    Right=NULL;
    key=a;
    l_height=0;
    r_height=0;
    balance_factor=0;

}
Node::~Node(){}
int Node::getkey()
{
    return(key);
}
int Node::get_balance_factor()
{
    balance_factor=l_height-r_height;
    return(balance_factor);
}
int Node::get_lheight()
{
    return(l_height);
}
int Node::get_rheight()
{
    return(r_height);
}
Node* Node::getLeftChild()
{
    return(Left);
}
Node* Node::getRightChild()
{
    return(Right);
}
Node* Node::getParent()
{
    return(Parent);
}
bool Node::setkey(int newkey)
{
    key=newkey;
    return true;
}
bool Node::set_balancefactor()
{
    balance_factor=l_height-r_height;
    return true;
}
bool Node::set_lheight(int new_lh)
{
    l_height=new_lh;
    return true;
}
bool Node::set_rheight(int new_rh)
{
    r_height=new_rh;
    return true;
}
bool Node::setParent(Node* new_Node)
{
    Parent=new_Node;
    return true;
}
bool Node::setLeftChild(Node* new_Node)
{
    Left=new_Node;
    return true;
}
bool Node::setRightChild(Node* new_Node)
{
    Right=new_Node;
    return true;
}
