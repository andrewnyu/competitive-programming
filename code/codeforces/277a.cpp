#include <iostream>
using namespace std;
const int MAXV = 101;

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
 
int parent[MAXV]; 
bool visited[MAXV]; 
void init_graph(graph *g){
    for(int i=0; i<MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
        parent[i] = -1;
        visited[i] = false;
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
            dfs(y,g);
        }
        p = p->next;
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    bool lng[n+1][m+1]; //adjaceny matrix if emp i knows lang j
    int cnt_lng[n+1];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            lng[i][j] = false;
        }
        cnt_lng[i] = 0;
    }
    
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        for(int j=0; j<k; j++){
            int a;
            cin>>a;
            lng[i][a-1] = true;
            cnt_lng[i]++;
        }
    }

    graph *g;
    g = new graph;
    init_graph(g);

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            for(int k=0; k<m; k++){
                if(lng[i][k] && lng[j][k]){
                    add_edge(i,j,g,false);
                }
            }
        }
    }

    int cnt_cc = 0;
    int cnt_nan = 0;
    for(int i=0; i<n; i++){
        if(cnt_lng[i] == 0){
            cnt_nan++;
        }
        else if(!visited[i]){
            cnt_cc++;
            dfs(i, g);
        }
    }

    if(cnt_cc>0){
        cnt_cc -= 1;
    }


    cout<<cnt_nan + cnt_cc<<endl;

}