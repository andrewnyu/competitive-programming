//ABC126D: Even Relation
#include <iostream>
#include <vector>
using namespace std;

//if distance is even then same color, else different
//path from any other node will pass parent. If its an even path they //will be same color, else different

const int MAXV = 100001;
vector < pair<int,long long int> > g[MAXV+1];

bool ok[MAXV+1];
bool color[MAXV+1];
void dfs(int v){
	ok[v]=true;
	for(int i=0; i<g[v].size(); i++){
		if(!ok[g[v][i].first]){
			if(g[v][i].second%2==0){
				color[g[v][i].first]=color[v];
			}
			else{
				color[g[v][i].first]=!color[v];
			}
			dfs(g[v][i].first);
		}
	}
}

int main(){
	int n;
	cin>>n;

	for(int i=1; i<=n; i++){ok[i]=false;}

	for(int i=0; i<n-1; i++){
		int a,b;
		long long int w;
		cin>>a>>b>>w;
		g[a].push_back(make_pair(b,w));
		g[b].push_back(make_pair(a,w));
	}

	color[1] = true;
	dfs(1);

	for(int i=1; i<=n; i++){
		cout<<color[i]<<endl;
	}


}