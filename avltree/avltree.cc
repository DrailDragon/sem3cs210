#include "avltree.h"
avltree::avltree()
{
    root=NULL;
    nodeCount=0;
}
avltree::~avltree(){}
int avltree::Tree_height(Node* rootNode)
{
    int l=0,r=0,maxm=1;
    if(rootNode==NULL)
        return 0;
    else 
    {
       // if(rootNode && rootNode->getLeftChild()!=NULL)
            l=rootNode->get_lheight();

        //if(rootNode && rootNode->getRightChild()!=NULL)
            r=rootNode->get_rheight();
        if(l>r)
        maxm=l+1;
        else
            maxm=r+1;
        return maxm;

    }

}
int avltree::Get_treeheight()
{
    cout<<"Height is:"<<Tree_height(root)<<endl;
}
Node* avltree::LL_rotate(Node* vNode)
{
     Node* l=vNode->getLeftChild();


        Node* lr=NULL;

            if(l->getRightChild()!=NULL)
                lr=l->getRightChild();
    if(vNode->getParent()==NULL)
    {

          vNode->setLeftChild(NULL);
          l->setParent(NULL);
          l->setRightChild(NULL);
          vNode->setParent(l);
          l->setRightChild(vNode);
          if(lr)
          {lr->setParent(vNode);
          vNode->setLeftChild(lr);
	  vNode->set_lheight(Tree_height(lr));
          }else
		{
		vNode->setLeftChild(NULL);
		vNode->set_lheight(0);
		}
	  l->set_rheight(Tree_height(vNode));
	root = l;
    }
    else
        {
            Node* pr=vNode->getParent();
            if(pr->getLeftChild()==vNode)
                pr->setLeftChild(l);
            else
                pr->setRightChild(l);
          l->setParent(pr);
          if(lr)
          {lr->setParent(vNode);
          vNode->setLeftChild(lr);
	  vNode->set_lheight(Tree_height(lr));
	   }else
		{
		vNode->setLeftChild(NULL);
		vNode->set_lheight(0);
		}
	l->setRightChild(vNode);
	vNode->setParent(l);
	 l->set_rheight(Tree_height(vNode));
        }
        return l;

}
Node* avltree::RR_rotate(Node* vNode)
{

    Node* r=vNode->getRightChild();
    Node* rl=NULL;
    if(vNode->getParent()==NULL)
    {
        vNode->setRightChild(NULL);
        r->setParent(NULL);
        if(r->getLeftChild()!=NULL)
            {
                rl=r->getLeftChild();
                rl->setParent(vNode);
                vNode->setRightChild(rl);
		vNode->set_rheight(Tree_height(rl));
            }else
		{
		vNode->setRightChild(NULL);
		vNode->set_rheight(0);		
		}
            r->setLeftChild(vNode);
            vNode->setParent(r);
	   r->set_lheight(Tree_height(vNode));
	root = r;
    }
    else
        {
            Node* pr=vNode->getParent();
            vNode->setRightChild(NULL);
            r->setParent(pr);
            if(pr->getLeftChild()==vNode)
                pr->setLeftChild(r);
            else
                pr->setRightChild(r);
            vNode->setParent(r);
            if(r->getLeftChild()!=NULL)
            {

             rl=r->getLeftChild();
             rl->setParent(vNode);
             vNode->setRightChild(rl);
	    vNode->set_rheight(Tree_height(rl));
            }else
		{
		vNode->setRightChild(NULL);
		vNode->set_rheight(0);		
		}


            r->setLeftChild(vNode);
            vNode->setParent(r);
	   r->set_lheight(Tree_height(vNode));
        }
        return r;

}
Node* avltree::LR_rotate(Node* vNode)
{
    Node* l=vNode->getLeftChild();
    Node* lr=l->getRightChild();
    Node* lrl=NULL;
    l->setParent(NULL);
    vNode->setLeftChild(lr);
    lr->setParent(vNode);
    if(lr->getLeftChild()!=NULL)
     {

       lrl=lr->getLeftChild();
       lrl->setParent(l);
       l->setRightChild(lrl);
       l->set_rheight(Tree_height(lrl));
     }else
	{
	l->setRightChild(NULL);
	l->set_rheight(0);
	}
     lr->setLeftChild(l);
     l->setParent(lr);
     
     lr->set_lheight(Tree_height(l));
    return LL_rotate(vNode);

}
Node* avltree::RL_rotate(Node* vNode)
{
    Node* r=vNode->getRightChild();
    Node* rl=r->getLeftChild();
    Node* rlr=NULL;
    vNode->setRightChild(rl);
    rl->setParent(vNode);
    if(rl->getRightChild()!=NULL)
    {
        rlr=rl->getRightChild();
        rlr->setParent(r);
        r->setLeftChild(rlr);
	r->set_lheight(Tree_height(rlr));
    }else
	{
	r->setLeftChild(NULL);
	r->set_lheight(0);
	}	
    rl->setRightChild(r);
    r->setParent(rl);
    rl->set_rheight(Tree_height(r));
    return RR_rotate(vNode);
}


bool avltree::Insert_Node(Node* newNode)
{
    if(root==NULL){
        root=newNode;
	cout<<"Inserted\t"<<root->getkey()<<"\ttotal number of nodes is:"<<nodeCount+1<<endl;
	nodeCount++;
    return true;
	}
    else{
	Node* temp=root;
	while(temp)
		{
		 if(temp->getkey()==newNode->getkey())
			{
				cout<<"Duplicate exists so can't insert"<<endl;
				return false;
			}
		 if(temp->getkey()>newNode->getkey())
			{
				if(temp->getLeftChild()==NULL)
					{
						temp->setLeftChild(newNode);
						newNode->setParent(temp);
						cout<<"Inserted\t"<<newNode->getkey()<<"\ttotal number of nodes is:"<<nodeCount+1<<endl;
						nodeCount++;
						Node* tmp=NULL;
						Node* p = temp;
						temp->set_lheight(1);
						while(p!=root){
								p=p->getParent();
								if(temp == p->getLeftChild())
									{
									p->set_lheight(Tree_height(temp));
									cout<<"balance factor of "<<p->getkey()<<"\tis\t"<<p->get_balance_factor()<<endl;
									temp=p;
									//p->set_balance_factor();
									}
								else{
									p->set_rheight(Tree_height(temp));
									temp=p;
									//p->set_balance_factor();
								    }
								if(p->get_balance_factor()==2)
									{
									tmp=p->getLeftChild();
									if(tmp->get_balance_factor()==1)
										LL_rotate(p);
									else
										LR_rotate(p);
									break;
									}
								else if(p->get_balance_factor()==-2)
									{
									tmp=p->getRightChild();
									if(temp->get_balance_factor()==-1)
										RR_rotate(p);
									else
										RL_rotate(p);
									break;
									}
							}
						return true;
					}
				else{
					temp = temp->getLeftChild();
					continue; 
				    }
			}
		if(temp->getkey()<newNode->getkey())
			{
				if(temp->getRightChild()==NULL)
					{
						temp->setRightChild(newNode);
						newNode->setParent(temp);
						cout<<"Inserted\t"<<newNode->getkey()<<"\ttotal number of nodes is:"<<nodeCount+1<<endl;
						nodeCount++;
						Node* p = temp;
						Node* tmp=NULL;
						temp->set_rheight(1);
						while(p!=root){
								p = p->getParent();
								if(temp == p->getLeftChild())
									{
									p->set_lheight(Tree_height(temp));
									temp = p;
									cout<<"balance factor of "<<p->getkey()<<"\tis\t"<<p->get_balance_factor()<<endl;
									//p->set_balance_factor();
									}
								else{
									p->set_rheight(Tree_height(temp));
									temp = p;
									//p->set_balance_factor();
								    }
								if(p->get_balance_factor()==2)
									{
									tmp = p->getLeftChild();
									if(tmp->get_balance_factor()==1)
										LL_rotate(p);
									else
										LR_rotate(p);
									break;
									}
								else if(p->get_balance_factor()==-2)
									{
									tmp = p->getRightChild();
									if(tmp->get_balance_factor()==-1)
										RR_rotate(p);
									else
										RL_rotate(p);
									break;
									}
							}
						return true;
					}
				else{
					temp = temp->getRightChild();
					continue;
				    }
			}
			
		}
		
	}
    
}
Node* avltree::search_Node(Node* sNode,int x)
            {

                if(sNode->getkey()==x)
                    return sNode;
                else if(x<sNode->getkey())
		{
		   if(sNode->getLeftChild()==NULL)
			return NULL;
		   else
                search_Node(sNode->getLeftChild(),x);
		}
                else{
		    if(sNode->getRightChild()==NULL)
			return NULL;
		    else
                    search_Node(sNode->getRightChild(),x);
                }

            }
Node* avltree::Tree_searchNode(int x)
        {
	    if(root==NULL)
		return NULL;
	   else
            return(search_Node(root,x));

        }
bool avltree::Update_Element(int x,int y)
        {
            Node* temp=Tree_searchNode(x);
            if(temp)
            {
	      Node* tmp = delete_Node(temp);
	      if(tmp){
		  cout<<"deleted\t"<<tmp->getkey()<<endl;
		  tmp->setkey(y);
		  Insert_Node(tmp);
		}
            return true;
            }
            else
                return false;
        }
bool avltree::balance_tree(Node* bNode)
{
	Node* tmp=NULL;
	Node* p=bNode;
	while(p!=NULL)
	{
	if(p->getLeftChild()==bNode)
	p->set_lheight(Tree_height(bNode));
	else if(p->getRightChild()==bNode)
	p->set_rheight(Tree_height(bNode));
	if(p->get_balance_factor()==2)
	{
		tmp=p->getLeftChild();
		if(tmp->get_balance_factor()==1)
		LL_rotate(p);
		else
		LR_rotate(p);
	}
	else if(p->get_balance_factor()==-2)
	{
		tmp=p->getRightChild();
		if(tmp->get_balance_factor()==-1)
		RR_rotate(p);
		else
		RL_rotate(p);
	}
	p=p->getParent();
    }
	return true;
}
Node* avltree::delete_Node(Node* vNode)
{


    Node* pr=NULL;
    if(vNode->getLeftChild()==NULL && vNode->getRightChild()==NULL)
    {
        if(vNode==root)
            return vNode;
        pr=vNode->getParent();
        if(pr->getLeftChild()==vNode)
	{
            pr->setLeftChild(NULL);
	    pr->set_lheight(0);
	}
        else
	{
            pr->setRightChild(NULL);
	    pr->set_rheight(0);
	}
        vNode->setParent(NULL);
	balance_tree(pr);
        return vNode;
    }
    if(vNode->getLeftChild()!=NULL && vNode->getRightChild()==NULL)
    {
        Node* l=vNode->getLeftChild();
        if(vNode==root)
        {
            root->setLeftChild(NULL);
            l->setParent(NULL);
	    root = l;
	    nodeCount--;
            return vNode;
        }
        pr=vNode->getParent();
        if(pr->getLeftChild()==vNode)
	{
            pr->setLeftChild(l);
	    pr->set_lheight(Tree_height(l));
	}
        else
	{
            pr->setRightChild(l);
	    pr->set_rheight(Tree_height(l));
	}
            l->setParent(pr);
            vNode->setLeftChild(NULL);
            vNode->setParent(NULL);
	    balance_tree(pr);
            nodeCount--;
            return vNode;

        }

        if( vNode->getRightChild()!=NULL)
        {
            Node* r=vNode->getRightChild();
            Node* r1=r;
	     Node* rp=NULL;
            while(r->getLeftChild()!=NULL)
                r=r->getLeftChild();
	    if(r1!=r)
               {
		rp=r->getParent();
	    if(rp->getLeftChild()==r)
		{
                    rp->setLeftChild(NULL);
		    rp->set_lheight(0);
		}
                else
		{
                    rp->setRightChild(NULL);
		    rp->set_rheight(0);
		}
                    r->setParent(NULL);

            if(r->getRightChild()!=NULL)
            {
                Node* rr=r->getRightChild();
                rr->setParent(rp);
                if(rp->getLeftChild()==r)
		{
                    rp->setLeftChild(rr);
		    rp->set_lheight(Tree_height(rr));
		}
                else
		{
                    rp->setRightChild(rr);
		    rp->set_rheight(Tree_height(rr));
		}
            }
		r1->setParent(r);
                r->setRightChild(r1);
		r->set_rheight(Tree_height(r1));
	      }
                vNode->setRightChild(NULL);
		 if(vNode->getLeftChild()!=NULL)
                {
                    Node* l=vNode->getLeftChild();
                    l->setParent(r);
                    r->setLeftChild(l);
		    r->set_lheight(Tree_height(l));
                    vNode->setLeftChild(NULL);
                }
                if(vNode!=root)
                {
                      pr=vNode->getParent();
                    vNode->setParent(NULL);
                    if(pr->getLeftChild()==vNode)
			{
                        pr->setLeftChild(r);
			pr->set_lheight(Tree_height(r));
			}
                    else
			{
                        pr->setRightChild(r);
			pr->set_rheight(Tree_height(r));
			}
                    r->setParent(pr);
                }else
		{
			r->setParent(NULL);
			root=r;
		}
	if(r!=r1)
		balance_tree(rp);
	else
		balance_tree(r);
            return vNode;
        }
}
Node* avltree::find_inorder_successor(Node* gNode)
        {
            Node* r=NULL;
	    if(gNode==NULL)
		return NULL;
	    else
            if(gNode->getRightChild()!=NULL)
            {

                r=gNode->getRightChild();
                while(r->getLeftChild()!=NULL){
                    r=r->getLeftChild();
			}
                return r;
            }
            else
            {
                Node* gp=NULL;
                if(gNode==root)
                    return NULL;
                gp=gNode->getParent();
                if(gp->getLeftChild()==gNode)
                    return gp;
                else if(gp->getParent()==NULL)
                    return NULL;
                else
                    {
                        Node* pp=gp->getParent();
                        while(pp!=NULL && pp->getLeftChild()!=gp)
                        {
                            gp=pp;
                            pp=pp->getParent();

                        }
                        return pp;
                    }
            }

        }
Node* avltree::find_inorder_predecessor(Node* gNode)
        {
	    if(gNode==NULL)
			return NULL;
	  else
            if(gNode->getLeftChild()!=NULL)
            {
                Node* l=gNode->getLeftChild();
                while(l->getRightChild()!=NULL)
                    l=l->getRightChild();
                return l;
            }
            else
            {
                if(gNode==root)
                    return NULL;
                Node* gp=gNode->getParent();
                if(gp->getRightChild()==gNode)
                    return gp;
                else
                {
                    Node* pp=gp->getParent();
                    while(pp!=NULL && gp!=pp->getRightChild())
                    {
                        gp=pp;
                        pp=pp->getParent();
                    }
                    return pp;

                }
            }
        }
bool avltree::check_binarytreeproperty(Node*rootNode)
{
    Node* l=NULL;
    Node* r=NULL;
    bool flag = 0;
    if(rootNode)
	{
    if(rootNode->getRightChild()!=NULL)
            {  r=rootNode->getRightChild();
                 if(rootNode->getkey()>r->getkey())
                   flag = 1;
                     check_binarytreeproperty(l);
            }
    if(rootNode->getLeftChild()!=NULL)
      {
          l=rootNode->getLeftChild();
          if(rootNode->getkey()<l->getkey())
           flag = 1;
          check_binarytreeproperty(r);
      }
    }
     if(flag==0)
      return true;
     else 
	return false;
}
bool avltree::check_balancefactor(Node* rootNode)
{
    bool flag = 0;
	if(rootNode)
	{
        if(rootNode->getLeftChild()!=NULL)
    check_balancefactor(rootNode->getLeftChild());
	int i=rootNode->get_balance_factor();
    if(i>=2 || i<=-2)
        flag=1;
    if(rootNode->getRightChild()!=NULL)
    check_balancefactor(rootNode->getRightChild());
    
	}
	if(flag==0)
	return true;
    else
	return false;
}
bool avltree::check_if_balanced_avltree()
{
    if(check_binarytreeproperty(root) && check_balancefactor(root))
    {
        cout<<"ya,it's an avl tree"<<endl;
        return true;
    }
    else
    {
        cout<<"Not an avl tree"<<endl;
        return false;
    }
}
bool avltree::Inorder_traversal(Node* rootNode)

{
    Node* l=NULL;
    Node* p=NULL;
    Node* r=NULL;
    if(rootNode->getLeftChild()!=NULL)
    {
        l=rootNode->getLeftChild();
        Inorder_traversal(l);
    }
    if(rootNode->getParent()!=NULL)
    {

    p=rootNode->getParent();
        cout<<rootNode->getkey()<<" "<<"Parent is"<<" "<<p->getkey()<<endl;
    }
    else
        cout<<rootNode->getkey()<<" "<<"parent is"<<" "<<"NULL"<<endl;
        if(rootNode->getRightChild()!=NULL)
        {
            r=rootNode->getRightChild();
            Inorder_traversal(r);
        }
    return true;
}
bool avltree::Tree_inordertraversal()
{
    cout<<"there are"<<nodeCount<<"entries:"<<endl;
    Inorder_traversal(root);
}
bool avltree::Preorder_traversal(Node* rootNode)
{
     Node* l=NULL;
    Node* p=NULL;
    Node* r=NULL;
    if(rootNode->getParent()!=NULL)
    {

    p=rootNode->getParent();
        cout<<rootNode->getkey()<<" "<<"Parent is"<<" "<<p->getkey()<<endl;
    }
    else
        cout<<rootNode->getkey()<<" "<<"parent is"<<" "<<"NULL"<<endl;
        if(rootNode->getLeftChild()!=NULL)
    {
        l=rootNode->getLeftChild();
        Preorder_traversal(l);
    }
     if(rootNode->getRightChild()!=NULL)
        {
            r=rootNode->getRightChild();
            Preorder_traversal(r);
        }
        return true;
}
bool avltree::Tree_preordertraversal()
{
     cout<<"there are"<<nodeCount<<"entries:"<<endl;
    Preorder_traversal(root);
}
bool avltree::Postorder_traversal(Node* rootNode)
{
    Node* l=NULL;
    Node* p=NULL;
    Node* r=NULL;
    if(rootNode->getLeftChild()!=NULL)
    {
        l=rootNode->getLeftChild();
        Postorder_traversal(l);
    }
    if(rootNode->getRightChild()!=NULL)
        {
            r=rootNode->getRightChild();
            Postorder_traversal(r);
        }
        if(rootNode->getParent()!=NULL)
    {

    p=rootNode->getParent();
        cout<<rootNode->getkey()<<" "<<"Parent is"<<" "<<p->getkey()<<endl;
    }
    else
        cout<<rootNode->getkey()<<" "<<"parent is"<<" "<<"NULL"<<endl;
return true;
}
bool avltree::Tree_postordertraversal()
{
     cout<<"there are"<<nodeCount<<"entries:"<<endl;
    return(Postorder_traversal(root));
}

