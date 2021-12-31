//CF 862B: Mahmoud and Ehab and the bipartiteness
#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 100001;
vector <int> g[MAXV+1];
bool ok[MAXV+1];
bool color[MAXV+1];

void dfs(int v){
	ok[v]=true;
	for(int i=0; i<g[v].size(); i++){
		if(!ok[g[v][i]]){
			color[g[v][i]]=!color[v];
			dfs(g[v][i]);
		}
	}
}

int main(){
	int n;
	cin>>n;

	for(int i=0; i<n-1; i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i=1; i<=n; i++){ok[i]=false;}
	color[1]=true;
	dfs(1);

	long long int cnt=0; //cnt of color A
	for(int i=1; i<=n; i++){
		if(color[i]){
			cnt+=1;
		}
	}

	long long int res = (cnt*(n-cnt))-n+1;
	cout<<res<<endl;



}