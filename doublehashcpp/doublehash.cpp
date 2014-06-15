#include "doublehash.h"
db_hash::db_hash(int num,int k_value,int buck_size){
	n=num;
	k=k_value;
	dh1= new dh**[n];
	for(int i=0;i<n;i++)
	dh1[i]= new dh*[k];
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++)
		dh1[i][j]=new dh[buck_size];
	}
	local_size=new int*[n];
	for(int i=0;i<n;i++)
	local_size[i]=new int[k];
	localcount=new int*[n];
	for(int j=0;j<n;j++)
	localcount[j]=new int[k];
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++)
		local_size[i][j]=buck_size;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++)
		localcount[i][j]=0;
	}
}
db_hash::~db_hash(){
}
bool db_hash::isempty_table(){
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++)
		if(localcount[i][j]!=0)
		return false;
	}
	return true;
}
int db_hash::binary_searchdelete(dh*** d,int i1,int i2,element* el){
	/*if(isempty_table()){
		cout<<"Table empty"<<endl;
		return -2;
	}*/
	if(localcount[i1][i2]==0)
	return -2;
	int p1=0,p2=0,mid;
	if(d[i1][i2][p1].elem->getdata()==el->getdata())
	return p1;
	else if(d[i1][i2][p2].elem->getdata()==el->getdata())
	return p2;
	else{
		while(p1<p2){
		mid=(p1+p2)/2;
		if(d[i1][i2][mid].elem->getdata()==el->getdata())
		return mid;
		else if(d[i1][i2][mid].elem->getdata()>el->getdata())
		p1=mid+1;
		else
		p2=mid-1;
			}
		if(p1==p2){
			if(d[i1][i2][p1].elem->getdata()==el->getdata())
			return p1;
			else
			return -1;
		}
	}
}
int db_hash::binary_searchinsert(dh*** d,int i1,int i2,element* el){
/*	if(isempty_table()){
		cout<<"Table empty"<<endl;
		return -2;
	}*/
	if(localcount[i1][i2]==0)
	return -2;
	int p1=0,p2=0,mid;
	if(d[i1][i2][p1].elem->getdata()==el->getdata())
	return -1;
	else if(d[i1][i2][p2].elem->getdata()==el->getdata())
	return -1;
	else{
		while(p1<p2){
		mid=(p1+p2)/2;
		if(d[i1][i2][mid].elem->getdata()==el->getdata())
		return -1;
		else if(d[i1][i2][mid].elem->getdata()>el->getdata())
		p1=mid+1;
		else
		p2=mid-1;
			}
		if(p1==p2){
			if(d[i1][i2][p1].elem->getdata()==el->getdata())
			return -1;
			else
			return p1;
		}
	}
}
int db_hash::get_bucketnumber(element* el){
	return ((el->getdata()%(n*k))+1);
}
int db_hash::get_hash1(int b_num){
	return (b_num-1)%n;
}
int db_hash::get_hash2(int b_num,int h_index1){
	return(b_num-1-(k*h_index1));
}
bool db_hash::insert_elem(element* el){
	int b_num = get_bucketnumber(el);
	int i1=get_hash1(b_num);
	int i2=get_hash2(b_num,i1);
	int index = binary_searchinsert(dh1,i1,i2,el);
	if(index==-1){
		cout<<"duplicate exists"<<endl;
		return false; 
	}
	if(index==-2){
		dh1[i1][i2][localcount[i1][i2]++].elem=el;
		cout<<"entry"<<" "<<dh1[i1][i2][localcount[i1][i2]-1].elem->getdata()<<"\tinserted into bucket"<<" "<<get_bucketnumber(dh1[i1][i2][localcount[i1][i2]-1].elem)<<"\tat index"<<" "<<localcount[i1][i2]<<endl;
		return true;
	}
	if(localcount[i1][i2]==local_size[i1][i2]){
		cout<<"bucket full, incrementing bucket-size twice"<<endl;
		dh* d1= new dh[2*local_size[i1][i2]];
		for(int i=0;i<localcount[i1][i2];i++)
		d1[i]=dh1[i1][i2][i];
		delete dh1[i1][i2];
		dh1[i1][i2]=d1;
		d1=NULL;
		localcount[i1][i2]*=2;
	}
	if(el->getdata()>dh1[i1][i2][index].elem->getdata()){
		for(int i=index+1;i<localcount[i1][i2];i++)
		dh1[i1][i2][i+1]=dh1[i1][i2][i];
		dh1[i1][i2][index+1].elem=el;
		localcount[i1][i2]++;
	cout<<"entry"<<" "<<dh1[i1][i2][index+1].elem->getdata()<<"\tinserted into bucket"<<" "<<get_bucketnumber(dh1[i1][i2][index+1].elem)<<"\tat index"<<" "<<localcount[i1][i2]<<endl;
	}else{
	for(int i=index;i<localcount[i1][i2];i++)
		dh1[i1][i2][i+1]=dh1[i1][i2][i];
		dh1[i1][i2][index].elem=el;
		localcount[i1][i2]++;	
			cout<<"entry"<<" "<<dh1[i1][i2][index].elem->getdata()<<"\tinserted into bucket"<<" "<<get_bucketnumber(dh1[i1][i2][index].elem)<<"\tat index"<<" "<<localcount[i1][i2]<<endl;
	}
	
	return true;
}
bool db_hash::delete_elem(element* el){
	int b_num = get_bucketnumber(el);
	int i1=get_hash1(b_num);
	int i2=get_hash2(b_num,i1);
	int index = binary_searchdelete(dh1,i1,i2,el);
	if(index<=-1){
		cout<<"Element not found"<<endl;
		return false; 
	}
	cout<<"element"<<" "<<dh1[i1][i2][index].elem->getdata()<<"deleted from bucket number"<<" "<<get_bucketnumber(dh1[i1][i2][index].elem)<<"\t from index number"<<" "<<index+1<<endl;
	delete dh1[i1][i2][index].elem;
	if(index!=localcount[i1][i2]-1){
	 for(int i=index;i<localcount[i1][i2]-1;i++)
	 dh1[i1][i2][i]=dh1[i1][i2][i+1];	
	}
    localcount[i1][i2]--;
    return true;
}
bool db_hash::print_table(){
	if(isempty_table()){
		cout<<"Table is empty"<<endl;
		return false;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cout<<"bucket number"<<" "<<n*i+j+1<<endl;
			for(int l=0;l<localcount[i][j];l++)
			cout<<dh1[i][j][l].elem->getdata()<<" ";
			cout<<endl;
		}
	}
	return true;
}
element* db_hash::search_elem(element* el){
	int b_num = get_bucketnumber(el);
	int i1=get_hash1(b_num);
	int i2=get_hash2(b_num,i1);
	int index = binary_searchdelete(dh1,i1,i2,el);
	if(index<=-1){
		cout<<"Element not found"<<endl;
		return NULL; 
	}
cout<<"element"<<" "<<dh1[i1][i2][index].elem->getdata()<<"found in bucket number"<<" "<<get_bucketnumber(dh1[i1][i2][index].elem)<<"\t from index number"<<" "<<index+1<<endl;
	return dh1[i1][i2][index].elem;
}
