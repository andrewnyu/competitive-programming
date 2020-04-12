#include <iostream>
using namespace std;
const int MAXV = 201;
 
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
bool prev_visited[MAXV];
int parent[MAXV]; 
int color[MAXV];
 
void init_graph(graph *g){
    for(int i=0; i<MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
        visited[i] = false;
        prev_visited[i] = false;
        parent[i] = -1;
        color[i] = 1;
    }
}

bool possible;
void check_graph(int v, graph *g){
    visited[v] = true;
    edgenode *p;
    p = new edgenode;
    p = g->edges[v];
 
    while(p!=NULL){
        int y = p->y;
        if(!visited[y]){
            parent[y] = v;
            color[y] = 1-color[v];
            check_graph(y, g);
        }
        else{
            if(color[y]==color[v]){
                possible = false;
            }
        }
        p = p->next; 
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        graph *g;
        g = new graph;
        init_graph(g);
        possible = true;
        int v,e;
        cin>>v>>e;
        for(int i=0; i<e; i++){
            int a,b;
            cin>>a>>b;
            add_edge(a,b,g,false);
        }

        int ans = 0;
        for(int i=0; i<v; i++){
            if(!visited[i]){
                check_graph(i, g);
            }
            
            int cnt_cc = 0;
            int ans_cc = 0;
            for(int j=0; j<v; j++){
                if(visited[j] && !prev_visited[j]){
                    prev_visited[j] = true;
                    cnt_cc++;
                    ans_cc += color[j];
                }
            }

            if(cnt_cc>1 && (cnt_cc-ans_cc<ans_cc)){
                ans_cc = cnt_cc - ans_cc;
            }

            ans += ans_cc;
        }

        if(possible){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}