#include "graph.h"
graph::graph(int siz)
{
	n=siz;
	int i,j;
	G=new int*[n];
	for( j=0;j<n;j++)
	G[j]=new int[n];
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				G[i][j]=0;
		}
}
graph::~graph(){}
bool graph::AddEdge(int x,int y)
{
	if(x>n-1 || y>n-1){
		cout<<"Enter the both ends of the edge(i.e. vertices) less than"<<n<<endl;
		return false;
	}
	if(G[x][y]==1 && G[y][x]==1){
		cout<<"An edge already exists betwen"<<x<<"\tand\t"<<y<<endl;
		return false;
	}
	G[x][y]=1;
	G[y][x]=1;
	cout<<"New edge added between"<<x<<"\tand\t"<<y<<endl;
	return true;
}
bool graph::deleteEdge(int x,int y)
{
	if(x>n-1 || y>n-1){
		cout<<"Enter the both ends of the edge(i.e. vertices) less than"<<n<<endl;
		return false;
	}
	if(G[x][y]==0 && G[y][x]==0){
		cout<<"No edge exists betwen"<<x<<"\tand\t"<<y<<endl;
		return false;
	}
	G[x][y]=0;
	G[y][x]=0;
	return true;
}
bool graph::BFS(int s)
{
	if(s>n-1){
		cout<<"Enter a source vertex less than "<<n<<endl;
		return false;
	}
int i,j;
que* q1=new que(n);
int ancestor[n];
	for(i=0;i<n;i++)
	 	ancestor[i]=0;
bool visited[n];
	for(j=0;j<n;j++)
		visited[j]=false;
int depth[n];
	for(i=0;i<n;i++)
	depth[i]=0;
	q1->enque(s);
	int k;
	visited[s]=true;
	ancestor[s]=s;
	depth[s]=0;
	while(!q1->if_empty())
	{
		k=q1->dequeue();
		cout<<"vertex is"<<" "<<k<<" "<<"ancestor is"<<""<<ancestor[k]<<" "<<"depth from source vertex is"<<" "<<depth[k]<<endl;
		for(i=0;i<n;i++)
		{
			if(visited[i]==false && G[k][i]==1)
			{
				visited[i]=true;
				q1->enque(i);
				depth[i]=depth[k]+1;
				ancestor[i]=k;
			}
		}

	}
	cout<<endl;
	delete q1;
	return true;
}
bool graph::DFS(int s)
{
	if(s>n-1){
		cout<<"Enter a source vertex less than "<<n<<endl;
		return false;
	}
stack1* s1=new stack1(n);
int j;
bool visited[n];
	for(j=0;j<n;j++)
		visited[j]=false;
int k,i;
int depth[n];
int ancestor[n];
	for(i=0;i<n;i++)
		depth[i]=0;
	for(j=0;j<n;j++)
		ancestor[j]=0;
	s1->push(s);
	visited[s]=true;
	ancestor[s]=s;
	while(!s1->if_empty())
	{
		k=s1->pop();
		cout<<"vertex is"<<" "<<k<<" "<<"ancestor is"<<""<<ancestor[k]<<" "<<"depth from source vertex is"<<" "<<depth[k]<<endl;
	for(i=n-1;i>=0;i--)
	{
		if(visited[i]==false && (G[k][i]==1 || G[i][k]==1))
		{
			visited[i]=true;
			s1->push(i);
			depth[i]=depth[k]+1;
			ancestor[i]=k;
		}
	}

	}
	cout<<endl;
	delete s1;
	return true;
}
bool graph::get_numberofcomponents(int s)
{
	if(s>n-1){
		cout<<"Enter a source vertex less than "<<n<<endl;
		return false;
	}
	int count=1,i,j,unvisited,f=0;
	bool visited[n];
	for(j=0;j<n;j++)
		visited[j]=false;
	int ancestor[n];
	for(j=0;j<n;j++)
		ancestor[j]=0;
	int depth[n];
	for(i=0;i<n;i++)
		depth[i]=0;
	BFS1(s,visited,ancestor,depth);
	unvisited=s;
	while(unvisited<n)
	{

		while(visited[unvisited]==true)
		{
			unvisited++;
		}
		s=unvisited;
		if(s==n)
			continue;
		if(BFS1(s,visited,ancestor,depth))
		count++;	
	}
	cout<<"graph has "<<" "<<count<<"components"<<endl;
	return true;
}
bool  graph::check_ifbipartite(int s)
{
	if(s>n-1){
		cout<<"Enter a source vertex less than "<<n<<endl;
		return false;
	}
	int flag=0,i,j;
	bool visited[n];
	for(j=0;j<n;j++)
		visited[j]=false;
	int ancestor[n];
	for(j=0;j<n;j++)
		ancestor[j]=0;
	int depth[n];
	for(i=0;i<n;i++)
		depth[i]=0;
	BFS1(s,visited,ancestor,depth);
	for(i=s;i<n;i++)
	{
		for(j=0;j<n,j!=i;j++)
		{
			if(depth[i]==depth[j])
				{
					if(G[i][j]==1 || G[j][i]==1)
						flag=1;
				}
		}
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<n,j!=i;j++)
		{
			if(depth[i]==depth[j])
				{
					if(G[i][j]==1 || G[j][i]==1)
						flag=1;
				}
		}
	}
	if(flag==1)
	cout<<"graph is not bipartite"<<endl;
	else
	cout<<"graph is bipartite"<<endl;
	return true;
}
bool graph::BFS1(int s,bool* visited,int* ancestor,int* depth)
{
	if(s>n-1){
		cout<<"Enter a source vertex less than "<<n<<endl;
		return false;
	}
int i,j;
que* q1=new que(n);
	q1->enque(s);
	int k;
	visited[s]=true;
	ancestor[s]=s;
	depth[s]=0;
	while(!q1->if_empty())
	{
		k=q1->dequeue();
		cout<<"vertex is"<<" "<<k<<" "<<"ancestor is"<<""<<ancestor[k]<<" "<<"depth from source vertex is"<<" "<<depth[k]<<endl;
		for(i=0;i<n;i++)
		{
			if(visited[i]==false && G[k][i]==1)
			{
				visited[i]=true;
				q1->enque(i);
				depth[i]=depth[k]+1;
				ancestor[i]=k;
			}
		}

	}
	cout<<endl;
	delete q1;
	return true;
}
bool graph::print_graph_matrix(){
		cout<<"\t";
	for(int k=0;k<n;k++){
		cout<<k<<"\t";
		}
		cout<<endl;
	for(int k=0;k<n;k++){
		cout<<" _"<<"  _"<<"\t";
		}
		cout<<"_"<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<"|"<<"\t";
		for(int j=0;j<n;j++)
			cout<<G[i][j]<<"\t";
		cout<<endl;
	}
return true;
}
