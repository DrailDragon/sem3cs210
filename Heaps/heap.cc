#include "heap.h"
heap::heap()
{
    a=NULL;
    siz=0;
}
heap::heap(int* newary,int n)
{
    a=new int[n];
    for(int i=0;i<n;i++)
        a[i]=newary[i];
    siz=n-1;
}
heap::~heap()
{
    delete a;
}
int heap::getParent(int i)
{
     if(i<1 || a==NULL)
    {
        return -1;
    }
    return(i/2);
}
int heap::getLeftChild(int i)
{
     if(i<1 || a==NULL)
    {
        return -1;
    }
    return(2*i);
}
int heap::getRightChild(int i)
{
     if(i<1 || a==NULL)
    {
        return -1;
    }
    return(2*i+1);
}
int heap::getmax()
{
     if(a==NULL)
    {
        return false;
    }
    return(a[0]);
}
bool heap::max_heapify(int* ary,int i)
{
    int l,r,largest=i,tmp;
    l=getLeftChild(i);
    r=getRightChild(i);
    if(i<0 || ary==NULL)
    {
        return false;
    }
    if(l!=-1 && l<=siz+1 && ary[largest-1]<ary[l-1])
    {
        largest=l;

    }
    if(r!=-1 && r<=siz+1 && ary[largest-1]<ary[r-1])
    {
        largest=r;
    }
    if(largest!=i)
    {
        tmp=ary[i-1];
        ary[i-1]=ary[largest-1];
        ary[largest-1]=tmp;
	max_heapify(ary,largest);
    }
	  
    return true;
}
int heap::extract_max()
{
    int maxm=a[0];
     if( a==NULL)
    {
        return false;
    }
    a[0]=a[siz];
    a[siz]=maxm;
    max_heapify(a,1);
    siz-=1;
    return(maxm);
    
}
bool heap::build_maxheap(int* ary)
{
    int x=siz+1;
    for(int i=x/2;i>0;i--)
    {
        max_heapify(ary,i);
    }
    return true;
}
bool heap::heap_buildmaxheap(){
	return build_maxheap(a);
}
bool heap::heap_sort()
{
    int x;
   int count=siz;
    while(siz!=0)
    {
        x=a[0];
    a[0]=a[siz];
    a[siz]=x;
    siz--;
    max_heapify(a,1);
    }
    for(int k=0;k<=count;k++)
        cout<<" "<<a[k]<<" "; 
     siz = count;
     //build_maxheap(a);
    return true;
}
bool heap::print_heap(){
	if(a==NULL)
	{
	cout<<"Heap is empty"<<endl;
	return false;
	}
	for(int i=0;i<siz+1;i++)
	{
	  int l = getLeftChild(i+1);
          int r = getRightChild(i+1);
	  int lchild=(l!=-1 && l<=siz+1)?a[l-1]:-1;
	  int rchild=(r!=-1 && r<=siz+1)?a[r-1]:-1;
	cout<<"Element\t"<<a[i]<<"\tleft\t"<<lchild<<"\tright\t"<<rchild<<endl;
	}
	return true;
}
