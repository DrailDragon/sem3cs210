/** \brief This file is written by Pintu Kumar,Btech 2nd Year licensed under CSE DEPT. IIT GUWAHATI.
 *
 *   This file is header file for Btree Class.To implement the attributes and methods of this class you must include this file into your programming
 *  file.
 *
 *
 *
 * \param root is the root Node for the Binary Tree.
 * \param nodecount keeps track of how many nodes tree contains
 * \return Two types of functions this Class has one return boolean type and other Pointer to some Node
 *
 */

#ifndef BTREEHEADER//If already defined ignore the codes till #endif
#define BTREEHEADER// Executing this line starts a new file BTREEHEADERThis header file is included to utilize the attributes of Node class
#include "Node.h"//using namespace std;//This file insures that whatever keywords or names whose namespaces  are not specified belong to std namespace
class Btree
{
    Node* root;
 int nodecount;
    public:
    Btree();
    bool Insert(Node*);
    bool insert(Node* rootNode,Node* newNode);
    Node* delete_Node(int);
    Node* search_Node(Node*,int);
    Node* Search_Node(int);
    Node* find_predecessor(int);
    Node* find_successor(int);
    bool inorder_traversal(Node*);
    bool preorder_traversal(Node*);
    bool postorder_traversal(Node*);
     bool Inorder_traversal();
    bool Preorder_traversal();
    bool Postorder_traversal();
    Node* find_MAX(Node*);
    Node* find_min(Node*);
    Node* find_MAX();
    Node* find_min();
   virtual ~Btree();




};

#endif // BTREEHEADER
