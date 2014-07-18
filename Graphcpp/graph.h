#ifndef G_HEADER
#define G_HEADER
#include "stack.h"
#include "que.h"
#include<iostream>
using namespace std;
class graph
{
int** G;
int n;
public:
graph(int);
virtual ~graph();
bool AddEdge(int,int);
bool deleteEdge(int,int);
bool DFS(int);
bool BFS(int);
bool BFS1(int,bool*,int*,int*);//used to find number of components
bool get_numberofcomponents(int);
bool check_ifbipartite(int);
bool print_graph_matrix();
};
#endif
