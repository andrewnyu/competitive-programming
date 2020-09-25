//cf598D: Igor in the Museum
#include <iostream>
using namespace std;
const int MAXV = 1000;
bool e[MAXV+1][MAXV+1];
bool v[MAXV+1][MAXV+1];

pair <int,int> p[MAXV+1][MAXV+1];
int d[MAXV+1][MAXV+1];

int n,m,k;
int cnt;
int cx,cy;
void dfs(int x, int y){
	v[x][y]=true;
	if(x<n-1){
		if(!e[x+1][y]){
			cnt+=1;
		}
		else if(!v[x+1][y] && e[x+1][y]){
			p[x+1][y].first = cx;
			p[x+1][y].second = cy;
			dfs(x+1,y);
		}
	}
	if(y<m-1){
		if(!e[x][y+1]){
			cnt+=1;
		}
		else if(!v[x][y+1] && e[x][y+1]){
			p[x][y+1].first = cx;
			p[x][y+1].second = cy;
			dfs(x,y+1);
		}
	}
	if(x>0){
		if(!e[x-1][y]){
			cnt+=1;
		}
		else if(!v[x-1][y] && e[x-1][y]){
			p[x-1][y].first = cx;
			p[x-1][y].second = cy;
			dfs(x-1,y);
		}
	}
	if(y>0){
		if(!e[x][y-1]){
			cnt+=1;
		}
		else if(!v[x][y-1] && e[x][y-1]){
			p[x][y-1].first = cx;
			p[x][y-1].second = cy;
			dfs(x,y-1);
		}
	}
}


int main(){
	cin>>n>>m>>k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char a;
			cin>>a;
			if(a=='.'){
				e[i][j]=true;
			}
			else{
				e[i][j]=false;
			}
		}
	}

	for(int i=0; i<k; i++){
		int x,y;
		cin>>x>>y;
		if(!v[x-1][y-1]){
			cnt=0;
			cx=x-1, cy=y-1;
			p[x-1][y-1].first=x-1;
			p[x-1][y-1].second=y-1;
			dfs(x-1,y-1);
			d[x-1][y-1]=cnt;
			cout<<cnt<<endl;
		}
		else{
			cout<<d[p[x-1][y-1].first][p[x-1][y-1].second]<<endl;
		}
	}
}