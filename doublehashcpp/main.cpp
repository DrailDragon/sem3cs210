#include "doublehash.h"
#include "element.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	db_hash* dbh1=NULL;
	int i,j;
	int nv,kv,buck_size;
	element* el_node=NULL;
	int ent;
	int choice;
	do{
		cout<<"Choose your option:"<<endl;
		cout<<"1.Create new table"<<endl;
		cout<<"2.Insert an element"<<endl;
		cout<<"3.Search element"<<endl;
		cout<<"4.Delete element"<<endl;
		cout<<"5.Print table"<<endl;
		cout<<"Enter any other option to exit"<<endl;
		cin>>choice;
		cout<<"You entered"<<" "<<choice<<endl;
		switch(choice){
			case 1:
				if(dbh1!=NULL)
				delete dbh1;
				cout<<"Enter n(first-index),k(second-index) and initial bucket-size in order"<<endl;
				cin>>nv;
				cin>>kv;
				cin>>buck_size;
				dbh1=new db_hash(nv,kv,buck_size);
				break;
			case 2:
				if(dbh1==NULL){
					cout<<"Create new table first"<<endl;
					break;
				}
				cout<<"Enter the integer to insert into table"<<endl;
				cin>>ent;
				el_node=new element();
				el_node->setdata(ent);
				dbh1->insert_elem(el_node);
				el_node=NULL;
				break;
			case 3:
					if(dbh1==NULL){
					cout<<"Create new table first"<<endl;
					break;
					}
			   cout<<"Enter the integer to search in the table"<<endl;
			  cin>>ent;	
			  el_node=new element();
			  el_node->setdata(ent);
			  dbh1->search_elem(el_node);
			  break;
			case 4:
				if(dbh1==NULL){
						cout<<"Create new table first"<<endl;
						break;
					}
				cout<<"Enter the element to delete"<<endl;
				cin>>ent;
				el_node=new element();
				el_node->setdata(ent);
				dbh1->delete_elem(el_node);	
				break;
			case 5:
				if(dbh1==NULL){
						cout<<"Create new table first"<<endl;
						break;
					}
					dbh1->print_table();
					break;
				default:
					cout<<"Exiting:"<<endl;
					return 0;
		}
	}while(true);
	return 0;
}
