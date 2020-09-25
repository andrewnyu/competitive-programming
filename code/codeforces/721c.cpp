//CF721C: Journey
#include <iostream>
#include <vector>
using namespace std;

int n,m,T;
vector < pair<int,int> > g[5001];
int dp[5001][5001];
int parent[5001][5001];
void dfs(int v, int j){
	//cout<<v<<endl;
	for(int i=0; i<g[v].size(); i++){
		int y = g[v][i].first;
		int time = g[v][i].second;


		if(dp[v][j]+time<=T && dp[y][j+1]>dp[v][j]+time){
			dp[y][j+1] = dp[v][j] + time;
			parent[y][j+1] = v;
			dfs(y, j+1);
		}
	}
}

int main(){
	cin>>n>>m>>T;

	for(int i=0; i<m; i++){
		int u,v,t;
		cin>>u>>v>>t;
		g[u-1].push_back(make_pair(v-1,t));
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			dp[i][j] = T+1;
		}
	}
	
	dp[0][0] = 0;
	dfs(0,0);

	int res=1;
	for(int i=1; i<n; i++){
		if(dp[n-1][i]<=T){
			res=i+1;
		}
	}

	cout<<res<<endl;

	vector <int> path;
	int ridx = res-1;
	int idx = n-1;
	path.push_back(idx+1);
	while(idx!=0){
		path.push_back(parent[idx][ridx]+1);
		idx = parent[idx][ridx];
		ridx-=1;
	}

	for(int i=0; i<res; i++){
		cout<<path[res-1-i]<<" ";
	}


}