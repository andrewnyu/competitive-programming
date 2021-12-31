//CF1600J: Robot Factory
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 1e3;

bool ok[MAXV+1][MAXV+1];
int d[MAXV+1][MAXV+1];
int g[MAXV+1][MAXV+1];
int n,m;

int current;

void dfs(int x, int y){
    ok[x][y] = true;
    current += 1;

    if(x>0){
        //check if south gate ..
        if(!ok[x-1][y] && !(g[x][y] & 1)){
            d[x-1][y] = d[x][y]+1;
            dfs(x-1, y);
        }
    }
    if(y>0){
        if(!ok[x][y-1] && !(g[x][y] & 8)){
            d[x][y-1] = d[x][y]+1;
            dfs(x, y-1);
        }
    }
    if(x<m-1){
        if(!ok[x+1][y] && !(g[x][y] & 4)){
            d[x+1][y] = d[x][y]+1;
            dfs(x+1, y);
        }
    }
    if(y<n-1){
        if(!ok[x][y+1] && !(g[x][y] & 2)){
            d[x][y+1] = d[x][y]+1;
            dfs(x, y+1);
        }
    }
}


int main(){

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>g[j][i];
            ok[j][i] = false;
            d[j][i] = 0;
        }
    }

    vector <int> res;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!ok[j][i]){
                current = 0;
                dfs(j, i);
                res.push_back(current);
            }
        }
    }

    sort(res.begin(), res.end(), greater<int>());
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

}