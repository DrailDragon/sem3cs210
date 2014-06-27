#include "avltree.h"
#include "node.h"
#include<iostream>
using namespace std;
int main()
{
    avltree* at1=NULL;
    Node* n1=NULL;
    Node* n2=NULL;
int i,n,choice;
do
{
    cout<<"Choose the option"<<endl;
    cout<<"1.Create new tree"<<endl;
    cout<<"2.Insert entry"<<endl;
    cout<<"3.Check if avltree"<<endl;
    cout<<"4.Inorder traversal"<<endl;
    cout<<"5.Preorder traersal"<<endl;
    cout<<"6.Postorder traversal"<<endl;
    cout<<"7.Delete entry"<<endl;
    cout<<"8.Get tree_height"<<endl;
    cout<<"9.Update entry"<<endl;
    cout<<"10.Search entry"<<endl;
    cout<<"11.Find inorder successor"<<endl;
    cout<<"12.Find inorder predecessor"<<endl;
    cout<<"Enter any other choice to exit"<<endl;
    cin>>choice;
    cout<<"You entered "<<" "<<choice<<endl;
    switch(choice)
    {
    case 1:
        if(at1!=NULL)
            delete at1;
        at1=new avltree();
        break;
    case 2:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
            cout<<"Enter the entry to insert"<<endl;
            cin>>i;
        n1=new Node(i);
        at1->Insert_Node(n1);
        break;
    case 3:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
            at1->check_if_balanced_avltree();
            break;
    case 4:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
            at1->Tree_inordertraversal();
            break;
    case 5:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
            at1->Tree_preordertraversal();
            break;
    case 6:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
            at1->Tree_postordertraversal();
            break;
    case 7:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
	    cout<<"Enter the entry to delete"<<endl;
	    cin>>i;
            n1=at1->Tree_searchNode(i);
            if(n1)
             {
              cout<<"Deleted"<<" "<<n1->getkey() <<endl;
               n2=at1->delete_Node(n1);
            delete n2;
             }
             else
                cout<<"Entry not found"<<endl;
    break;
    case 8:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
            at1->Get_treeheight();
            break;
    case 9:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
            cout<<"Enter the existing entry to be replaced and new entry to replace with"<<endl;
            cin>>i>>n;
            at1->Update_Element(i,n);
            break;


    case 10:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
            cout<<"Enter the entry to search"<<endl;
            cin>>i;
            n1=at1->Tree_searchNode(i);
            if(n1)
            cout<<"Entry found"<<endl;
            else
                cout<<"Entry not found"<<endl;
            break;
    case 11:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
            cout<<"Enter the entry to get its successor"<<endl;
            cin>>i;
            n1=at1->Tree_searchNode(i);
            n2=at1->find_inorder_successor(n1);
            if(n2)
            cout<<"Successor is:"<<" "<<n2->getkey()<<endl;
            else
                cout<<"Successor not found"<<endl;
            break;
    case 12:
        if(at1==NULL)
            cout<<"First create empty avltree"<<endl;
           cout<<"Enter the entry to get its predecessor"<<endl;
            cin>>i;
            n1=at1->Tree_searchNode(i);
            n2=at1->find_inorder_predecessor(n1);
            if(n2)
            cout<<"Predecessor is:"<<" "<<n2->getkey()<<endl;
            else
                cout<<"Predecessor not found"<<endl;
            break;
    default:
        return 0;


    }

}while(true);
return 0;
}
