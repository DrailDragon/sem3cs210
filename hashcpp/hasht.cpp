#include "hasht.h"
ht::ht(int numkey,int localsiz)
{
    n=numkey;
    mod=n;
    local_siz=new int[n];
    localcount=new int[n];
    h=new int*[n];
    for(int i=0;i<n;i++)
            h[i]=new int[localsiz];
    for(int j=0;j<n;j++)
        local_siz[j]=localsiz;
    for(int k=0;k<n;k++)
    localcount[k]=0;


}
ht::~ht(){}
int ht::get_htindex(int x)
{
    return(x%mod);
}
int ht::binary_searchdelete(int* a[],int y,int x)
{
    int p1=0,p2=localcount[y]-1,mid;
    if(a[y][p1]==x)
        return p1;
    else if(a[y][p2]==x)
        return p2;
    else
    {
        while(p1<p2)
        {
            mid=(p1+p2)/2;
            if(a[y][mid]==x)
                return mid;
            else if(a[y][mid]<x)
                p1=mid+1;
            else if(a[y][mid]>x)
                p2=mid-1;
        }
        if(p1==p2)
        {
            if(a[y][p1]==x)
                return p1;
            else
                return -1;
        }
    }
}

int ht::binary_searchinsert(int* a[],int y,int x)
{
    int p1=0,p2=localcount[y]-1,mid;
    if(a[y][p1]==x)
        return -1;
    else if(a[y][p2]==x)
        return -1;
    else
    {
        while(p1<p2)
        {
            mid=(p1+p2)/2;
            if(a[y][mid]==x)
                return -1;
            else if(a[y][mid]<x)
                p1=mid+1;
            else if(a[y][mid]>x)
                p2=mid-1;
        }
        if(p1==p2)
        {
            if(a[y][p1]==x)
                return -1;
            else
                return p1;
        }
    }
}

bool ht::insertentry(int entry)
{
    int indexkey=get_htindex(entry);
    int b=binary_searchinsert(h,indexkey,entry);
    if(b==-1)
        {cout<<"duplicate exists"<<endl;return false;}
    else
    {
        if(localcount[indexkey]==local_siz[indexkey])
        {
            cout<<"page is full,doubling the size of the page"<<endl;
            int* temp=new int[2*local_siz[indexkey]];
            for(int i=0;i<local_siz[indexkey];i++)
                temp[i]=h[indexkey][i];
            delete h[indexkey];
            h[indexkey]=temp;
            local_siz[indexkey]*=2;
            temp=NULL;
        }
            if(h[indexkey][b]>entry)
            {
                for(int i=b;i<localcount[indexkey];i++)
                    h[indexkey][i+1]=h[indexkey][i];
                h[indexkey][b]=entry;
                	cout<<"entry\t"<<h[indexkey][b]<<"\tinserted in bucket"<<" "<<indexkey+1<<"\tat index"<<" "<<b+1<<endl;
            }
            else if(h[indexkey][b]<entry)
            {
                for(int i=b+1;i<localcount[indexkey];i++)
                    h[indexkey][i+1]=h[indexkey][i];
                h[indexkey][b+1]=entry;
                	cout<<"entry\t"<<h[indexkey][b+1]<<"\tinserted in bucket"<<" "<<indexkey+1<<"\tat index"<<" "<<b+2<<endl;
            }
            localcount[indexkey]++;
      
        return true;
    }

}
int ht::searchentry(int elem)
{
    int index=get_htindex(elem);
    int b=binary_searchdelete(h,index,elem);
    if(b<0)
    {cout<<"Entry not found"<<endl;return false;}
    else
    {cout<<"Entry found at"<<"  "<<"bucket number="<<index+1<<"at index="<<b+1<<endl;return true;}

}
bool ht::deleteentry(int entry)
{ 	if(isempty_table()){
	cout<<"table is empty"<<endl;
	return false;
   } 
    int index=get_htindex(entry);
    int b=binary_searchdelete(h,index,entry);
    if(b<0)
    {
        cout<<"entry not found"<<endl;
        return false;
    }
    else
    {
    	cout<<"entry\t"<<h[index][b]<<"\tin bucket"<<" "<<index+1<<"\tat index"<<" "<<b+1<<"\tdeleted"<<endl;
        h[index][b]=0;
        if(b<localcount[index]-1)
        {
            for(int i=b;i<localcount[index]-1;i++)
                h[index][i]=h[index][i+1];
            localcount[index]--;
        }
        return true;
    }
}
bool ht::isempty_table(){
	if(n==0)
	return true;
	for(int i=0;i<n;i++)
	{
		if(localcount[i]!=0)
		return false;
	}
	return true;
}
bool ht::print_table(){
	if(isempty_table() ){
		cout<<"Table empty"<<endl;
		return false;
	}else{
		for(int i=0;i<n;i++){
			cout<<"bucket number = "<<i+1<<endl;
			for(int j=0;j<localcount[i];j++){
			cout<<"entry\t"<<h[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	return true;
}
