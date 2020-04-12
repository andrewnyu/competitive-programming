#include <iostream>
using namespace std;
const int MAXV = 50001;
 
struct edgenode{
    int y;
    struct edgenode *next;
};
 
struct graph{
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    bool directed; 
};
 
void add_edge(int a, int b, graph *g, bool directed){
    edgenode *p;
    p = new edgenode;
    p->y = b;
    p->next = g->edges[a];
 
    g->edges[a] = p;
    g->degree[a]++;
 
    if(!directed){
        add_edge(b, a, g, true);
    }
}
 
bool visited[MAXV];
int parent[MAXV]; 
 
void init_graph(graph *g){
    for(int i=0; i<MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
        visited[i] = false;
        parent[i] = -1;
    }
}
 
void dfs(int v, graph *g){
    visited[v] = true;
    edgenode *p;
    p = new edgenode;
    p = g->edges[v];
 
    while(p!=NULL){
        int y = p->y;
        if(!visited[y]){
            parent[y] = v;
            dfs(y, g);
        }
        p = p->next; 
    }
}
 
int main(){
    int n,r1,r2;
    graph *g = new graph;
    init_graph(g);
 
 
    cin>>n>>r1>>r2;
    for(int i=0; i<n; i++){
        int a;
        if(i != r1-1){
    	    cin>>a;
            add_edge(a-1, i, g, false);
        }    
    }
 
    dfs(r2-1, g);
    
 
    for(int i=0; i<n; i++){
        if(i!=r2-1){
            cout<<parent[i]+1<<" ";
        }
    }
 
}