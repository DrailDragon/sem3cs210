#include "hasht.h"
int main()
{
    ht* ht1=NULL;
    int i;
    int k,choice;
    do{
            cout<<"Choose the option"<<endl;
        cout<<"1. Create new hash table"<<endl;
        cout<<"2. Insert new entry"<<endl;
        cout<<"3. Search an entry"<<endl;
        cout<<"4. Delete an entry"<<endl;
        cout<<"5. Print all the entries slotwise"<<endl;
        cout<<" Enter any other  choice to exit"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        if(ht1!=NULL)
            delete ht1;
        cout<<"How many indexes and how many entries per slot"<<endl;
        cin>>i>>k;
        ht1=new ht(i,k);
        break;
    case 2:
        if(ht1==NULL)
        {cout<<"Create new hash table first"<<endl;break;}
        cout<<"Enter the entry to insert"<<endl;
        cin>>k;
        ht1->insertentry(k);
        break;
    case 3:
        if(ht1==NULL)
        {
            cout<<"Create new hash ta b le first"<<endl;
            break;
        }
        cout<<"Enter the entry to search"<<endl;
        cin>>k;
        ht1->searchentry(k);
        break;
    case 4:
        if(ht1==NULL)
        {
            cout<<"Create new hash table first"<<endl;
            break;
        }
        cout<<"Enter the entry to delete"<<endl;
        cin>>k;
        ht1->deleteentry(k);
        break;
    case 5:
        if(ht1==NULL)
        {
            cout<<"Create new hash table first"<<endl;
            break;
        }
        ht1->print_table();
        break;
    default:
        return 0;
    }
    }while(true);
    return 0;
}
 /*   #include "hasht.h"
int main()
{

    ht* h3=new ht(50000,1000);
    int k,l,m,n,p,r,s,t;
    for(k=0;k<50000000;k++)
    {
        cin>>l; h3->insertentryunsorted(l);

    }
    for(m=0;m<1000000;m++)
    {
        cin>>n; h3->deleteentryunsorted(n);
    }
    for(p=0;p<1000000000;p++)
    {
        cin>>r; h3->searchentrylinear(r);
    }
    return 0;
}*/

