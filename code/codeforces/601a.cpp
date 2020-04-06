#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXV = 401;


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


int get_min_path(int start, int n, graph *g){
        bool possible = false;
        queue <int> q;
        q.push(start);
        visited[start] = true;

        //bfs
        while(!q.empty()){
            int v = q.front();
            q.pop();

            edgenode *p;
            p = new edgenode;
            p = g->edges[v];

            while(p!=NULL){
                int y = p->y;
                if(!visited[y]){
                    q.push(y);
                    parent[y] = v;
                    visited[y] = true;

                    if(y==n) possible = true;
                }
                p = p->next;
            }
            
        }

        //get len of shortest path
        int cnt = 0;
        if(possible){
            int v = n;
            while(v!=start){
                v = parent[v];
                cnt++;
            }
        }

        else{
            cnt = -1;
        }
        return cnt;
}

int main(){
    int n,m;
    cin>>n>>m;

    bool adj[401][401] = {false};
    bool rd[401][401] = {false}; 
    for(int i=1; i<401; i++)for(int j=1; j<401; j++){
        adj[i][j] = false;
        rd[i][j] = false;
    }

    graph *tr;
    graph *bs;
    tr = new graph;
    bs = new graph;
    init_graph(tr);
    init_graph(bs);

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a][b] = true;
        adj[b][a] = true;
        add_edge(a,b,tr,false);
    }

    for(int i=1; i<=n; i++)for(int j=1; j<=n; j++){
        if(i!=j && !adj[i][j]){
            rd[i][j] = true;
            rd[j][i] = true;
            add_edge(i,j,bs,false);
        }
    }


    int ans = 0;
    if(adj[1][n]){
        //bfs rd to find shortest path to n, if impossible return -1
        //start at v = 1
        ans = get_min_path(1,n,bs);
    }
    else{
        ans = get_min_path(1,n,tr);
    }

    cout<<ans<<endl;



}