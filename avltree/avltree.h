#ifndef AVLTREEHEADER
#define AVLTREEHEADER
#include "node.h"
#include<iostream>
using namespace std;
class avltree
{
    Node* root;
    int nodeCount;
public:
    avltree();
    avltree(int*,int);
    ~avltree();
    bool Insert_Node(Node*);

     Node* LL_rotate(Node*);

     Node* RR_rotate(Node*);
    Node* LR_rotate(Node*);
    Node* RL_rotate(Node*);
    bool Inorder_traversal(Node*);
    bool Tree_inordertraversal();
    bool Preorder_traversal(Node*);
    bool Tree_preordertraversal();
    bool Postorder_traversal(Node*);
    bool Tree_postordertraversal();
    Node* delete_Node(Node*);
    Node* search_Node(Node*,int);
    Node* Tree_searchNode(int);
    Node* find_inorder_successor(Node*);
    Node* find_inorder_predecessor(Node*);
    int Tree_height(Node*);
    int Get_treeheight();
    bool Update_Element(int,int);
    bool check_if_balanced_avltree();
    bool check_binarytreeproperty(Node*);
    bool check_balancefactor(Node*);
    bool balance_tree(Node*);

};
#endif // AVLTREEHEADER
