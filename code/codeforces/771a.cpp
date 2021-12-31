//cf 771A: Bear and Friendship Condition
#include <iostream>
using namespace std;
const int MAXV = 150000;

struct node{
	int v;
	node *next;
};

struct graph{
	int degree[MAXV+1];
	node *edges[MAXV+1];
};

void add_edge(graph *g, int v1, int v2, bool directed){
	node *n1 = new node;
	n1->v=v2;
	n1->next=g->edges[v1];
	g->edges[v1] = n1;
	g->degree[v1]++;

	if(!directed){
		add_edge(g,v2,v1,true);
	}

}

bool visited[MAXV+1];
long long int cc_size,cc_cnt;
void dfs(graph *g, int v){
	visited[v]=true;
	cc_cnt++;
	cc_size+=g->degree[v];
	
	node *p= new node;
	p = g->edges[v];

	while(p!=NULL){
		int y=p->v;
		if(!visited[y]){
			dfs(g,y);
		}
		p=p->next;
	}
}


int main(){
	int n,m;
	cin>>n>>m;

	graph *g = new graph;
	for(int i=0; i<n; i++){
		visited[i]=false;
		g->edges[i]=new node;
		g->edges[i]=NULL;
		g->degree[i]=0;
	}

	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		add_edge(g,a-1,b-1,false);
	}

	bool pos = true;
	for(int i=0; i<n; i++){
		if(!visited[i]){
			cc_cnt=0;
			cc_size=0;
			dfs(g,i);

			if(cc_cnt>1){
				if(cc_size/2!=(cc_cnt*(cc_cnt-1)/2)){
					pos=false;
				}
			}
		}
	}

	if(pos){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}