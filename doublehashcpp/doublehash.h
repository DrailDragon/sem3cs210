#ifndef DB_HASH
#define DB_HASH
#include<iostream>
#include "element.h"
using namespace std;
class db_hash{
private:
	struct dh{
		  element* elem;
	      };
	dh*** dh1;//table
	int n;//first hash
	int k;//second hash
	int** localcount;//array of number of element-pointers contained in a bucket
	int** local_size;//array of size of buckets
	public:
		db_hash(int num,int k_value,int buck_size);//constructor input first hash_value(num) ,second hash_value(k_value),third initial bucket-size 
	virtual	~db_hash();//destructor
		int get_bucketnumber(element*);
		int get_hash1(int);//input bucket-number,return hashindex1
		int get_hash2(int,int);//return hashindex2
		bool insert_elem(element*);//insert element-pointer in the table input pointer to element(element*)
		bool delete_elem(element*);//remove element-pointer from the table input pointer to element(element*)
		int binary_searchinsert(dh***,int,int,element*);//function used in inserting an element-pointer into table,input table-pointer,first hash value,second hash-value,pointer to element to be searched 
		//returns -1 if element was found and index at which element should be inserted(index of just greater or lesser data) if was not found
		int binary_searchdelete(dh***,int,int,element*);//function used in deleting an element-pointer into table,input table-pointer,first hash value,second hash-value,pointer to element to be searched
		bool isempty_table(void);//returns true if table is empty other-wise false
	    bool print_table(void);//prints the table data along-with bucket-number and index in the bucket 
	    element* search_elem(element*);//returns pointer to element if element found
};
#endif //DB_HASH
