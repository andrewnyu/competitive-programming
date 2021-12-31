//CF 177C2: Party
#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 2001;

struct graph{
    vector <int> *edges[MAXV+1];
};

bool ok[MAXV+1];

bool current_ok[MAXV+1];
int current_cc;

void reset_ok(int n){
    for(int i=0; i<n; i++){
        current_ok[i] = false;
    }
}

void dfs(int v, graph *g){
    ok[v] = true;
    current_ok[v] = true;
    current_cc+=1;

    for(int i=0; i<(*(g->edges[v])).size(); i++){
        int current_v = (*(g->edges[v]))[i];
        if(!ok[current_v]){
            dfs(current_v, g);
        }
    }
}

int main(){

    int n,k,m;
    cin>>n;

    graph *g = new graph;
    for (int i=0; i<n; i++){
        g->edges[i] = new vector <int>;
    }

    cin>>k;
    for(int i=0; i<k; i++){
        int x,y;
        cin>>x>>y;
        
        (*(g->edges[x-1])).push_back(y-1);
        (*(g->edges[y-1])).push_back(x-1);
    }

    cin>>m;
    vector < pair<int,int> > en;
    for(int i=0; i<m; i++){
        int e1, e2;
        cin>>e1>>e2;

        en.push_back(make_pair(e1-1, e2-1));
    }

    int best = 0;
    for(int i=0; i<n; i++){
        if(!ok[i]){
            reset_ok(n);
            current_cc = 0;
            dfs(i, g);

            bool possible = true;
            for(int j=0; j<m; j++){
                if(current_ok[en[j].first] && current_ok[en[j].second]){
                    //both are in current graph
                    possible = false;
                    break;
                }
            }

            if(possible){
                best = max(best, current_cc);
            }

        }
    }

    cout<<best<<endl;



}