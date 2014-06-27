
#include "Btree.h"
Btree::Btree()
{

    root=NULL;
    nodecount=0;
}
Btree::~Btree(){
}
Node* Btree::search_Node(Node* rootNode,int searchdigit)
{
    if(rootNode==NULL)
        return(NULL);
    if(searchdigit==rootNode->getDigit())
        return(rootNode);

    if(searchdigit<rootNode->getDigit())
    {
       return search_Node(rootNode->getLeftChild(),searchdigit);
    }
    else
        {
           return search_Node(rootNode->getRightChild(),searchdigit);
        }

}
Node* Btree::Search_Node(int el){
	return search_Node(root,el);
}
bool Btree::inorder_traversal(Node* rootNode)
{
	 if(rootNode){
    inorder_traversal(rootNode->getLeftChild());
    cout<<" "<<rootNode->getDigit()<<" ";
    inorder_traversal(rootNode->getRightChild());
     return true;
	}
	 return false;
}
bool Btree::Inorder_traversal(){
	if(nodecount==0){
		cout<<"Tree is empty"<<endl;
		return false;
	}
	return inorder_traversal(root);
}
bool Btree::preorder_traversal(Node* rootNode)
{
     if(rootNode){
    cout<<" "<<rootNode->getDigit()<<" ";
    preorder_traversal(rootNode->getLeftChild());
    preorder_traversal(rootNode->getRightChild());
    return true;
	}
	return false;
}
bool Btree::Preorder_traversal(){
		if(nodecount==0){
		cout<<"Tree is empty"<<endl;
		return false;
	}
	return preorder_traversal(root);
}
bool Btree::postorder_traversal(Node* rootNode)
{
   
    if(rootNode){
    postorder_traversal(rootNode->getLeftChild());
    postorder_traversal(rootNode->getRightChild());
    cout<<" "<<rootNode->getDigit()<<" ";
    return true;
	}
	return false;
}
bool Btree::Postorder_traversal(){
		if(nodecount==0){
		cout<<"Tree is empty"<<endl;
		return false;
	}
	return postorder_traversal(root);
}
Node* Btree::find_MAX(Node* rootNode)
{
   
        if(rootNode==NULL || rootNode->getRightChild()==NULL)  
        return rootNode;
     else
         return find_MAX(rootNode->getRightChild());
}
Node* Btree::find_MAX(){
	return find_MAX(root);
}
Node* Btree::find_min(Node* rootNode)
{

    if(rootNode==NULL || rootNode->getLeftChild()==NULL)
        return(rootNode);
    else
       return find_min(rootNode->getLeftChild());

}
Node* Btree::find_min(){
	return find_min(root);
}


Node* Btree::find_predecessor(int digit)
{
    
    Node* tmp=search_Node(root,digit);

    if(tmp==NULL || (tmp->getParent()==NULL && tmp->getLeftChild()==NULL && tmp->getRightChild()==NULL))
        return(tmp);
    if(tmp->getLeftChild())
    {

       return(find_MAX(tmp->getLeftChild()));

        }
    if(tmp->getLeftChild()==NULL )
    {
        Node* prnt=tmp->getParent();
        if(prnt==NULL)
            return(NULL);
        if(tmp==prnt->getRightChild())
            return(prnt);
        else
            {
                Node* temp=prnt->getParent();
                while(temp!=NULL)
                {
                    if(temp->getRightChild()==prnt)
                        return(temp);
                    temp=temp->getParent();
                    prnt=prnt->getParent();

                }
                if(temp==NULL)
                    return(NULL);


            }
    }
}
Node* Btree::find_successor(int digit)
{
    Node* tmp=Search_Node(digit);
   
    if(tmp==NULL || (tmp->getParent()==NULL && tmp->getLeftChild()==NULL && tmp->getRightChild()==NULL))
        return(tmp);
        if(tmp->getRightChild()!=NULL)
        {
            return(find_min(tmp->getRightChild()));
        }
        else
        {
            Node* prnt=tmp->getParent();
            if(tmp==prnt->getLeftChild())
                return(prnt);
            Node* temp=prnt->getParent();
            while(temp!=NULL)
            {
                if(prnt==temp->getLeftChild())
                    return(temp);
                temp=temp->getParent();
                prnt=prnt->getParent();

            }
            if(temp==NULL)
                return(NULL);
        }

}
bool Btree::Insert(Node* newNode){
	return insert(root,newNode);
}
bool Btree::insert(Node* rootNode,Node* newNode)
{
    int i=newNode->getDigit();
    if(rootNode==NULL)
    {
         rootNode=newNode;
         nodecount++;
         cout<<"Inserted\t"<<rootNode->getDigit()<<endl;
    return true;

    }

    if(i>rootNode->getDigit())
    {
        if(rootNode->getRightChild()==NULL)
        {
           rootNode->setRightChild(newNode);
           newNode->setParent(rootNode);
           newNode->setRightChild(NULL);
           newNode->setLeftChild(NULL);
           nodecount++;
            cout<<"Inserted\t"<<rootNode->getDigit()<<endl;
           return true;
        }


         insert(rootNode->getRightChild(),newNode);
    }

    else if(i<rootNode->getDigit())
    {
        if(rootNode->getLeftChild()==NULL)
        {


            rootNode->setLeftChild(newNode);
            newNode->setParent(rootNode);
            newNode->setLeftChild(NULL);
            newNode->setRightChild(NULL);
            nodecount++;
             cout<<"Inserted\t"<<rootNode->getDigit()<<endl;
            return true;
        }
        insert(rootNode->getLeftChild(),newNode);
    }else{
    	cout<<"Duplicate exists"<<endl;
    	return false;
    }
        
}
Node* Btree::delete_Node(int deletedint)
{
    Node* deletednode=search_Node(root,deletedint);
    Node* snode=find_successor(deletedint);
    if(snode==NULL)
    {
        Node* leftchild=deletednode->getLeftChild();
        Node* prnt=deletednode->getParent();
        leftchild->setParent(deletednode->getParent());
        prnt->setRightChild(leftchild);
        deletednode->setParent(NULL);
        deletednode->setLeftChild(NULL);
        deletednode->setRightChild(NULL);
        nodecount--;
        return(deletednode);

    }
    else
        {
            int t=snode->getDigit();
            snode->setDigit(deletedint);
            deletedint=t;
            if(snode->getLeftChild()==NULL && snode->getRightChild()==NULL)
               {

                snode->setParent(NULL);
                nodecount--;
            return(snode);
			}
            else
                {
                    Node* Lchild=snode->getLeftChild();
                    Node* Rchild=snode->getRightChild();
                    Node* prt=snode->getParent();
                    if(Rchild==NULL)
                    {
                        Lchild->setParent(prt);
                        prt->setLeftChild(Lchild);
                        snode->setParent(NULL);
                        snode->setLeftChild(NULL);
                        nodecount--;
                        return(snode);
                        }
                        Rchild->setParent(prt);
                        prt->setRightChild(Rchild);
                         Lchild->setParent(prt);
                        prt->setLeftChild(Lchild);
                        snode->setParent(NULL);
                        snode->setLeftChild(NULL);
                          nodecount-=1;
                        return(snode);

                }
        }
      

}
