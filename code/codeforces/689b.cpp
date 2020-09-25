//CF 689B: Mike and Shortcuts
#include <iostream>
#include <queue>
using namespace std;
const int MAXV = 200001;
 
struct node{
	int y;
	node *next = NULL;
};
 
struct graph{
	node *edges[MAXV+1];
};
 
bool ok[MAXV+1];
int d[MAXV+1];
 
void bfs(graph *g, int v){
	d[v]=0;
	ok[v] = true;
	queue <int> q;
	q.push(v);
	
	while(!q.empty()){
		int y=q.front();
		q.pop();
		node *p = new node;
		p = g->edges[y];
		//cout<<y<<endl;
 
		while(p->next!=NULL){
			//cout<<p->y<<endl;
			if(!ok[p->y]){
				d[p->y] = d[y]+1;
				ok[p->y]=true;
				q.push(p->y);
			}
			p=p->next;
		}
	}
}
 
int main(){
	int n;
	cin>>n;
 
	graph *g = new graph;
	for(int i=0; i<n; i++){
		g->edges[i]=new node;
		ok[i]=false;
		d[i]=0;
	}

	for(int i=0; i<n; i++){
		//connect to preceding node
		if(i>0){
			node *p = new node;
			p->next=g->edges[i-1];
			p->y=i;
			g->edges[i-1] = p;
		}
 
		if(i<n-1){
			node *p = new node;
			p->next=g->edges[i+1];
			p->y=i;
			g->edges[i+1] = p;
		}
	}
 
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
 
		node *p = new node;
		p->next=g->edges[i];
		p->y=a-1;
		g->edges[i] = p;
 
	}
 
	bfs(g,0);
 
	for(int i=0; i<n; i++){
		cout<<d[i]<<" ";
	}
 
}