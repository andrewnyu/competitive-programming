#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXV = 200001;
 
 
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
 
 
void bfs(int start, graph *g){
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
 
                }
                p = p->next;
            }
            
        }

}
 
int main(){
    int n;
    cin>>n;

    graph *g;
    g = new graph;
    init_graph(g);

    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        add_edge(a,b,g,false);
    }

    vector <int> arr;
    vector <int> pos (n+1,-1);
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
        pos[a] = i;
    }

    bfs(1,g);

    parent[1] = 0;
    pos[0] = -1;
    bool possible = true;
    for(int i=1; i<n; i++){
        if(pos[parent[arr[i]]]<pos[parent[arr[i-1]]]){
            possible = false;
        }
    }

    if(possible){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }






 
 
 
}