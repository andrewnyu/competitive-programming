//Hackerrank: Breadth First Search: Shortest Reach
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXV = 1002;
 
 
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
int path[MAXV]; //shortest path from s
void init_graph(graph *g){
    for(int i=0; i<MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
        parent[i] = -1;
        visited[i] = false;
        path[i] = 0;
    }
}


void get_min_path(int start, graph *g){
        bool possible = false;
        queue <int> q;
        q.push(start);
        visited[start] = true;
        path[start] = 0;
 
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
                    path[y] = path[v] + 6;
                    visited[y] = true;

                }
                p = p->next;
            }
            
        }
}
 
int main(){
    int q;
    cin>>q;

    while(q--){
        int n,m;
        cin>>n>>m;

        graph *g = new graph;
        init_graph(g);

        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
            add_edge(a,b,g,false);
        }
        int s;
        cin>>s;

        get_min_path(s, g);
        vector<int>ans;
        for(int i=1; i<=n; i++){
            if(i!=s){
                if(path[i]==0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(path[i]);
                }
            }
        }
        

        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
 
 
 
}
