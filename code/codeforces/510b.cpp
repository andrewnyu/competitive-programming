#include <iostream>
#include <string>
using namespace std;
char color[51][51];
//grid dfs
int n,m;
bool visited[51][51];
int parent[51][51];
bool cycle;
void dfs(int x, int y, int p){
    if(visited[x][y]){
        if(parent[p/m][p%m]!=x*m + y)
            cycle = true;
    }
    else{
        visited[x][y] = true;
        parent[x][y] = p;
        int np = x*m + y;
        if(x<n-1){
            if(color[x+1][y]==color[x][y]){
                dfs(x+1, y,np);
            }
        }
        if(y<m-1){
            if(color[x][y+1]==color[x][y]){
                dfs(x, y+1, np);
            }
        }
        if(x>0){
            if(color[x-1][y]==color[x][y]){
                dfs(x-1, y, np);
            }
        }
        if(y>0){
            if(color[x][y-1]==color[x][y]){
                dfs(x, y-1, np);
            }
        }
    }
    
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>color[i][j];
        }
    }

    cycle=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                int start = i*m+j;
                dfs(i,j,start);
            }
        }
    }

    if(cycle){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

}