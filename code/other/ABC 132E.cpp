//ABC 132E: Hopscotch Addict
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 1e5+1;

//build edges between all vertices 3 spaces away
vector <int> * g[MAXV+1];
vector <int> * og[MAXV+1];

bool ok[MAXV+1][3] = {false};
long long int d[MAXV+1] = {0};

void init(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            ok[i][j] = false;
        }
        d[i] = 0;
    }
}

struct hop{
    int v, parent, chop;
};


void bfs (int v){
    ok[v][0] = true;
    d[v] = 0;
    queue < hop > q;
    q.push((hop) {v, v, 0});

    while(!q.empty()){
        int v = q.front().v;
        int p = q.front().parent;
        int chop = q.front().chop;
        q.pop();

        //cout<<v<<" "<<p<<" "<<chop<<endl;

        for(int i=0; i<(*g[v]).size(); i++){
            int cv = (*g[v])[i];

            if(chop==2 && !ok[cv][0]){
                ok[cv][0] = true;
                d[cv] = d[p]+1;
                q.push((hop) {cv, cv, 0});
            }
            else if(chop<2 && !ok[cv][chop+1]){
                ok[cv][chop+1] = true;
                q.push((hop) {cv, p, chop+1});
            }
            
        }
    }
}

int main(){

    int n,m;
    int s,t;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        g[i] = new vector <int>;
    }    
   
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        (*g[u-1]).push_back(v-1);
    } 

    cin>>s>>t;

    //init(n);
    bfs(s-1);
    if(ok[t-1][0]){
        cout<<d[t-1]<<endl;
    }
    else{
        cout<<-1<<endl;
    }



}
