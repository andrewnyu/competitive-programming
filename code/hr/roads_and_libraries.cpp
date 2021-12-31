//HR: Roads and Libraries
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 100001;

struct node{
	int v;
	node *next;
};

struct graph{
	node *edges[MAXV+1];
};

void add_edge(graph *g, int a, int b, bool directed){
	node *p = new node;
	p->v = b;
	p->next = g->edges[a];
	g->edges[a] = p;

	if(!directed){
		add_edge(g,b,a,true);
	}
}

long long int cc_size;
bool visited[MAXV+1];

void dfs(graph *g, int v){
	visited[v] = true;
	cc_size++;
	node *p = new node;
	p = g->edges[v];
	while(p!=NULL){
		if(!visited[p->v]){
			dfs(g, p->v);
		}
		p=p->next;
	}
}




int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n,m,cl,cr;
		cin>>n>>m>>cl>>cr;

		graph *g = new graph;
		for(int i=0; i<n; i++){
			visited[i] = false;
			g->edges[i] = NULL;
		}

		for(int i=0; i<m; i++){
			int a,b;
			cin>>a>>b;
			add_edge(g,a-1,b-1,false);
		}

		long long int res = 0;
		if(cr>=cl){
			res = n*cl;
		}
		else{
			for(int i=0; i<n; i++){
				if(!visited[i]){
					cc_size = 0;
					dfs(g,i);
					res += (cc_size-1)*cr + cl;
				}
			}
		}

		cout<<res<<endl;

	}
}