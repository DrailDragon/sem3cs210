#ifndef HASH_H
#define HASH_H
#include<iostream>
using namespace std;
class ht{
int** h;
int n;//No. of buckets
int* local_siz;//array containing size of all buckets
int* localcount;//array containing no. of entries in all buckets
int mod;
public:
    ht(int,int);
    ~ht();
    int get_htindex(int);
    int binary_searchinsert(int**,int,int);
    int binary_searchdelete(int**,int,int);
    bool insertentry(int);
    int searchentry(int);
    bool deleteentry(int);
    bool isempty_table();
    bool print_table(void);
    int linearsearch(int** a,int y,int x);
    bool insertentryunsorted(int entry);
    bool deleteentryunsorted(int entry);
    int searchentrylinear(int x);
};


#endif // HASH_H
