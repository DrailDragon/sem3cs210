#include "hasht.h"
int ht::linearsearch(int** a,int y,int x)
{
    int p1=0;
    while(p1<localcount[y])
    {
        if(a[y][p1]==x)
        return p1;
        else
        p1++;
    }
    if(p1==localcount[y])
    return -1;
}
bool ht::insertentryunsorted(int entry)
{
    int index=get_htindex(entry);
    int b=linearsearch(h,index,entry);
    if(b>=0)
    { cout<<"duplicate exists"<<endl;return false;}
    else
    {
        if(localcount[index]==local_siz[index])
        {
            cout<<"Bucket is full,doubling the size of the bucket"<<endl;
            int* tmp=new int[2*local_siz[index]];
            for(int i=0;i<localcount[index];i++)
            tmp[i]=h[index][i];
            delete h[index];
            h[index]=tmp;
            tmp=NULL;
            h[index][localcount[index]++]=entry;
             cout<<"entry"<<" "<<h[index][localcount[index]-1]<<" "<<"inserted into bucket number"<<" "<<index+1<<"\tat index"<<" "<<localcount[index]<<endl;
            local_siz[index]*=2;
        }
        else
        {
            h[index][localcount[index]++]=entry;
            cout<<"entry"<<" "<<h[index][localcount[index]-1]<<" "<<"inserted into bucket number"<<" "<<index+1<<"\tat index"<<" "<<localcount[index]<<endl;
        }
        return true;
    }
}
bool ht::deleteentryunsorted(int entry)
{
    int index=get_htindex(entry);
    int li=linearsearch(h,index,entry);
    if(li<0)
    {
        cout<<"entry is absent"<<endl;
        return false;
    }
    else
    {
        if(li==localcount[index]-1)
        {
		cout<<"entry\t"<<h[index][localcount[index]-1]<<"\tin bucket"<<" "<<index+1<<"\tat index"<<" "<<localcount[index]<<"\tdeleted"<<endl;
        h[index][--localcount[index]]=0;
	   
        }
        
        else
        {	cout<<"entry\t"<<h[index][localcount[index]-1]<<"\tin bucket"<<" "<<index+1<<"\tat index"<<" "<<li+1<<"\tdeleted"<<endl;
            h[index][li]=0;
            for(int j=li;j<localcount[index];j++)
            h[index][j]=h[index][j+1];
            localcount[index]--;
        }
        return true;
    }
}
int ht::searchentrylinear(int x)
{
        int index=get_htindex(x);

        int li=linearsearch(h,index,x);
        if(li<0)
        {
        cout<<"Entry not found"<<endl;return false;
        }
        else
        {
            cout<<"Entry found in the bucket number"<<index+1<<"  "<<"at index="<<" "<<li+1<<endl;return true;
        }
}
