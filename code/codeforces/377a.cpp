#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXV = 250000;
 
struct edgenode{
    int y;
    struct edgenode *next;
};
 
struct graph{
    edgenode *edges[MAXV];
    bool directed; 
};


void add_edge(int a, int b, graph *g, bool directed){
    edgenode *p;
    p = new edgenode;
    p->y = b;
    p->next = g->edges[a];
    g->edges[a] = p;
 
    if(!directed){
        add_edge(b, a, g, true);
    }
}
 
bool visited[MAXV];
bool preserve[MAXV];
void init_graph(graph *g){
    for(int i=0; i<MAXV; i++) {
        g->edges[i] = NULL;
        visited[i] = false;
        preserve[i] = false;
    }
}


int cnt;
void dfs(int v, int d, graph *g){
    cnt = cnt+1;
    if(cnt<=d){
        preserve[v] = true;
    }

    visited[v] = true;
    edgenode *p;
    p = new edgenode;
    p = g->edges[v];
 
    while(p!=NULL){
        int y = p->y;
        if(!visited[y]){
            dfs(y, d, g);
        }
        p = p->next; 
    }
}




int main(){
    int r,c,k;
    cin>>r>>c>>k;

    graph *g;
    g = new graph;
    init_graph(g);

    int cnt_path=0;
    vector <int> grid (r*c);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char a;
            cin>>a;
            if(a=='#'){
                grid[i*c+j%c]=0;
            }
            else{
                grid[i*c+j%c]=1;
                cnt_path++;
            }
        }
    }

    //build graph
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            vector <int> adj;
            int current = i*c + j%c;
            if(i>0){
                adj.push_back((i-1)*c + j%c);
            }
            if(i<r-1){
                adj.push_back((i+1)*c + j%c);
            }
            if(j>0){
                adj.push_back(i*c + (j-1)%c);
            }
            if(j<c-1){
                adj.push_back(i*c + (j+1)%c);
            }

            if(grid[current]==1){
                for(int v=0; v<adj.size(); v++){
                    if(grid[adj[v]]==1){
                        add_edge(current, adj[v], g, true);
                    }
                }
            }  
            
        }
    }

    cnt=0;
    for(int i=0; i<r*c; i++){
        if(grid[i]==1 && !visited[i]){
            dfs(i,cnt_path-k,g);
        }
    }


    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(preserve[i*c+j%c]){
                cout<<".";
            }
            else if(grid[i*c+j%c]==1){
                cout<<"X";
            }
            else{
                cout<<"#";
            }
        }
        cout<<endl;
    }

}