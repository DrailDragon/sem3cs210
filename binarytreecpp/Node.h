/**
*This file is written by Pintu Kumar.Personal,not licensed under any institution;
*Node class is entity of a binary tree.
*  Node has following components:
* Digit: an integer variable to store integer data in a node;
*parent: pointer to parent of a node.
*left: pointer to Left node of the node
*right: pointer to the right node of the node
*
*This file is header file for class Node
*
*
*/
#ifndef NODEHEADER
#define NODEHEADER
#include<iostream>
using namespace std;

class Node
{
    int Digit;
    Node* parent;
    Node* left;
    Node* right;
    //All the set functions return  boolean.All the get functions return the corresponding data type
public:
    Node(int a);//constructor with its data set
    Node();//constructor without setting its data.If you use this constructor you have to set  the data using setDigit() function
    virtual ~Node();//destructor
    bool setParent(Node*);//To make parent pointer referenced to some node
    Node* getParent();//Returns pointer to Parent node of a node
    bool setLeftChild(Node*);// To set left pointer to point  to some node
    Node* getLeftChild();//Returns pointer to left child of a node
    bool setRightChild(Node*);// To set right pointer to point to some node
    Node* getRightChild();//Returns the pointer to the right child of a node
    bool  setDigit(int);// To set the data of a node
    int getDigit();//Returns the data of a node


};
#endif
