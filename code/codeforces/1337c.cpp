#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const long long int MAXV = 200001;
 
struct edgenode{
    int y;
    struct edgenode *next;
};
 
struct graph{
    edgenode *edges[MAXV+1];
    long long int degree[MAXV+1];
    bool directed; 
};
 
void add_edge(long long int a, long long int b, graph *g, bool directed){
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
long long int parent[MAXV];
long long int cnt[MAXV];
long long int dist[MAXV];
void init_graph(graph *g){
    for(int i=0; i<MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
        visited[i] = false;
        parent[i] = -1;
        cnt[i]=0;
        dist[i]=0;
    }
}

void dfs(long long int v, graph *g){
    visited[v] = true;
    edgenode *p;
    p = new edgenode;
    p = g->edges[v];
 
    while(p!=NULL){
        long long int y = p->y;
        if(!visited[y]){
            parent[y] = v;
            dist[y]=dist[v]+1;
            dfs(y, g);
            cnt[v] = cnt[v]+cnt[y]+1;
        }
        p = p->next; 
    }
}
 
int main(){
    graph *g;
    g = new graph;
    init_graph(g);
 
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n-1; i++){
        long long int u,v;
        cin>>u>>v;
        add_edge(u,v,g,false);
    }
 
 
    dfs(1,g);
    vector <long long int> score (n);
    for(int i=0; i<n; i++){
        score[i] = cnt[i+1] - dist[i+1];
    }

    sort(score.begin(),score.end());
    long long int ans = 0; //capital city is always a tourist city
    for(int i=0; i<n-k; i++){
        ans += score[n-1-i];
    }
 
    cout<<ans<<endl;
 
    
}