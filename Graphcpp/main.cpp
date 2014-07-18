#include <iostream>
#include "graph.h"
using namespace std;
int main()
{

    int choice;
    graph* G=NULL;

do{
	cout<<"Enter your choice:";
	cout<<"1. Create new graph"<<endl;
	cout<<"2. Add a new edge to the graph"<<endl;
	cout<<"3. Delete an edge from the graph"<<endl;
	cout<<"4. BFS of graph"<<endl;
	cout<<"5. DFS of graph"<<endl;
	cout<<"6. Get the number of components of the graph"<<endl;
	cout<<"7. Check if bipartite"<<endl;
	cout<<"8. Print graph matrix"<<endl;
	cout<<"Any other choice to exit"<<endl;
	cin>>choice;
	cout<<"You entered "<<choice<<endl;
	switch(choice){
		case 1:
			if(G!=NULL){
				delete G;
			}
			int vcount;
			cout<<"How many vertices in your graph? "<<endl;
			cin>>vcount;
			G = new graph(vcount);
			cout<<"New graph with 0 edges and "<<vcount<<"\tnodes created"<<endl;
			//create graph with zero edges
			//vertices are labeled as 0, 1, 2...vcount-1
			//it is a simple undirected unweighted graph
			//you can use adjacency list of matrix to represent the graph
			break;

		case 2:
			if(G==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
			int v1, v2;
			cout<<"Enter first endpoint of edge"<<endl;
			cin>>v1;
			cout<<"Enter second endpoint of edge"<<endl;
			cin>>v2;
			G->AddEdge(v1,v2);
			break;

		case 3:
			if(G==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
			//int v1, v2;
			cout<<"Enter first endpoint of edge"<<endl;
			cin>>v1;
			cout<<"Enter second endpoint of edge"<<endl;
			cin>>v2;
			G->deleteEdge(v1,v2);
			break;

		case 4:
			if(G==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
		    int source;
		    cout<<"Enter source vertex for BFS"<<endl;
		    cin>>source;
		    G->BFS(source);

		    break;

		case 5:
			if(G==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
		   // int source;
		    cout<<"Enter source vertex for DFS"<<endl;
		    cin>>source;
		    G->DFS(source);
		    //Read section 22.3 from Cormen book
		    //DFS can be performed with multiple sources as well. However we will stick to the convention that DFS starts from a source and covers only reachable vertices
			break;
		case 6:
			if(G==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
			cout<<"Enter the lowest valued vertex in the graph"<<endl;
			cin>>v1;
			G->get_numberofcomponents(v1);
			break;
		case 7:
			if(G==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
			cout<<"Enter the lowest valued vertex in the graph"<<endl;
			cin>>v1;
			G->check_ifbipartite(v1);
			break;
		case 8:
			if(G==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
			G->print_graph_matrix();
			break;
		default:
			cout<<"Exiting"<<endl;
			return 0;
	}

}while(true);
    return 0;
}

