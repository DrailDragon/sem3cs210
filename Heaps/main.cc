#include "heap.h"
int main()
{
    heap* h1=NULL;
    int* b=NULL;
    int n1,k,ch,j;
    cout<<"\nPlease enter the no. of elements & integer elements of the array:"<<endl;
    cin>>n1;
    b=new int[n1];
    if(b==NULL)
	{
	 cout<<"Error allocating memory for array"<<endl;
	return 0;
	}
    for(j=0;j<n1;j++)
    cin>>b[j];
    do
        {
            cout<<"choose the option"<<endl;
            cout<<"1.fill array randomly"<<endl;
            cout<<"2.build_maxheap"<<endl;
            cout<<"3.Get maximum"<<endl;
            cout<<"4.Extract maximum"<<endl;
            cout<<"5.Heap sort"<<endl;
	    cout<<"6.Print heap"<<endl;
            cout<<"Enter any other key to exit"<<endl;
            cin>>ch;
	    cout<<"You entered\t"<<ch<<endl;
            switch(ch)
            {
            case 1:
                if(h1!=NULL)
                    delete h1;
                h1=new heap(b,n1);
		if(h1)
		cout<<"Randomly inserted into the array(proheap)"<<endl;
                break;
            case 2:
                if(h1==NULL)
			{
                    cout<<"Fill array randomly first"<<endl;
			break;
			}
                    h1->heap_buildmaxheap();
		    cout<<"Max heap built"<<endl;
                    break;
            case 3:
                if(h1==NULL)
			{
                    cout<<"Fill array randomly first"<<endl;
			break;
			}
                    cout<<"max is "<<" "<<h1->getmax()<<endl;
                    break;
            case 4:
                if(h1==NULL)
			{
                    cout<<"Fill array randomly first"<<endl;
			break;
			}
                  cout<<"max extracted"<<h1->extract_max()<<endl;
                    break;
            case 5:
                if(h1==NULL)
			{
                    cout<<"Fill array randomly first"<<endl;
			break;
			}
                    cout<<"Sorted array is "<<endl;
                h1->heap_sort();
		break;
	    case 6:
		if(h1==NULL)
			{
                    cout<<"Fill array randomly first"<<endl;
			break;
			}
		h1->print_heap();
              break;
            default:
		cout<<"Exiting"<<endl;
                return 0;

            }
        }while(true);
        return 0;
}
