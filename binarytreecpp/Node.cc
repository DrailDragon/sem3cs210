

#include "Node.h"
Node::Node()
{
    Digit=0;
    parent=NULL;
    right=NULL;
    left=NULL;
}
Node::Node(int a)
{

    Digit=a;
    parent=NULL;
    left=NULL;
    right=NULL;
}
Node::~Node(){
}
bool Node::setParent(Node* newNode)
{
    parent=newNode;
    return true;

}
Node* Node::getParent()
{
    return(parent);
}
bool Node::setLeftChild(Node* newNode)
{
    left=newNode;
    return true;

}
Node* Node::getLeftChild()
{
    return(left);
}
bool Node::setRightChild(Node* newNode)
{
    right=newNode;
    return true;
}
Node* Node::getRightChild()
{
    return(right);
}
bool Node::setDigit(int newDigit)
{
    Digit=newDigit;
    return true;
}
int Node::getDigit()
{
    return(Digit);
}
