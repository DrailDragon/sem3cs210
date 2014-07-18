#ifndef HEAPHEADER
#define HEAPHEADER
#include<iostream>
using namespace std;
class heap
{
    int *a;
    int siz;
 public:
    heap();
    heap(int*,int);
    ~heap();
    int getParent(int);
    int getLeftChild(int);
    int getRightChild(int);
    bool max_heapify(int*,int);
    int getmax();
    bool build_maxheap(int*);
    int extract_max();
    bool heap_sort();
    bool heap_buildmaxheap();
    bool print_heap();
};
#endif // HEAPHEADER
