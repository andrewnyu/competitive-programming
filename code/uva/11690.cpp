//uva 11690: money matters
#include <iostream>
using namespace std;
const int MAXV = 10001;

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
int balance [MAXV];
void init_graph(graph *g){
    for(int i=0; i<MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
        visited[i] = false;
        parent[i] = -1;
        balance[i] = 0;
    }
}

int cc_sum = 0;
void dfs_sum(int v, graph *g){
    visited[v] = true;
    edgenode *p;
    p = new edgenode;
    p = g->edges[v];
    cc_sum += balance[v];
 
    while(p!=NULL){
        int y = p->y;
        if(!visited[y]){
            parent[y] = v;
            dfs_sum(y, g);
        }
        p = p->next; 
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        graph *g = new graph;
        init_graph(g);
        //possible if the sum in each connected component = 0
        for(int i=0; i<n; i++){
            cin>>balance[i];
        }
        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
            add_edge(a,b,g,false);
        }

        bool possible = true;
        for(int i=0; i<n; i++){
            cc_sum = 0;
            if(!visited[i]){
                dfs_sum(i, g);
                if(cc_sum != 0){
                    possible = false;
                }
            }
        }

        if(possible){
            cout<<"POSSIBLE"<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }

    }
}