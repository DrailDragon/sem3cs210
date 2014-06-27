#include "Btree.h"
int main()
{
    Btree* b1=NULL;
    Node* n1=NULL;
    int k;
    int choice;
    do
    {	cout<<"Choose the option"<<endl;
        cout<<"1.create new Btree"<<endl;
        cout<<"2.Insert an integer"<<endl;
        cout<<"3.Inorder traversal"<<endl;
        cout<<"4.Preorder traversal"<<endl;
        cout<<"5.Postorder traversal"<<endl;
        cout<<"6.Find predecessor"<<endl;
        cout<<"7.Find successor"<<endl;
        cout<<"8.Delete node"<<endl;
        cout<<"Enter any other entry to exit"<<endl;
        cin>>choice;
        cout<<"You entered"<<" "<<choice<<" "<<endl;
        switch(choice)
        {
        case 1:
            if(b1!=NULL)
                delete b1;
            b1=new Btree();
            cout<<"New empty tree created"<<endl;
            break;
        case 2:
            if(b1==NULL){
            	 cout<<"First create empty tree"<<endl;
            	 break;
            }
             cout<<"Enter integer to insert"<<endl;
              cin>>k;
            n1=new Node(k);
            b1->Insert(n1);
            n1=NULL;
            break;
        case 3:
        	 if(b1==NULL){
            	 cout<<"First create empty tree"<<endl;
            	 break;
            }
            b1->Inorder_traversal();
            break;
        case 4:
        	 if(b1==NULL){
            	 cout<<"First create empty tree"<<endl;
            	 break;
            }
            b1->Preorder_traversal();
            break;
        case 5:	
         if(b1==NULL){
            	 cout<<"First create empty tree"<<endl;
            	 break;
            }
            b1->Postorder_traversal();
            break;
        case 6:
        	 if(b1==NULL){
            	 cout<<"First create empty tree"<<endl;
            	 break;
            }
            cout<<"Enter integer to find its predecessor"<<endl;
            cin>>k;
            n1=b1->find_predecessor(k);
            cout<<"Predecessor of"<<" "<<k<<"\tis\t"<<n1->getDigit()<<endl;
            break;
		case 7:
			 if(b1==NULL){
            	 cout<<"First create empty tree"<<endl;
            	 break;
            }
             cout<<"Enter integer to find its successor"<<endl;
            cin>>k;
            n1=b1->find_successor(k);
            cout<<"Successor of"<<" "<<k<<"\tis\t"<<n1->getDigit()<<endl;
            break;
        case 8:
        	if(b1==NULL){
            	 cout<<"First create empty tree"<<endl;
            	 break;
            }
             cout<<"Enter integer to delete"<<endl;
            cin>>k;
            n1=b1->delete_Node(k); 
			if(n1){    
            cout<<"Element\t"<<n1->getDigit()<<"\tdeleted"<<endl;
            delete n1;
        }
            else
            cout<<"Element not found"<<endl;
            break;
        default:
        	cout<<"Exiting"<<endl;
            	return 0;
        }

    }while(true);

return 0;
}
