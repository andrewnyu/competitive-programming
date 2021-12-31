//CF 429A: Xor-tree
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAXV = 1e5+1;

int cnt;
vector <int> res;
vector <int> g[MAXV+1];
bool act[MAXV+1], req[MAXV+1];

void dfs(int v, int p, int d, bool flip[]){
	bool flip1[3];
	memcpy(flip1, flip, 3*sizeof(bool));
	//create a copy since arrays pass by reference by default in c++

	if((act[v]==req[v])==flip1[d%2]){
		//cout<<v<<" "<<d<<" "<<flip1[d%2]<<endl;
		flip1[d%2] = !flip1[d%2];
		cnt+=1;
		res.push_back(v);
	}

	for(int i=0; i<g[v].size(); i++){
		int current = g[v][i];
		if(current!=p){
			dfs(current,v,d+1,flip1);
		}
	}
}


int main(){
	int n;
	cin>>n;

	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i=1; i<=n; i++){
		cin>>act[i];
	}
	for(int i=1; i<=n; i++){
		cin>>req[i];
	}

	cnt=0;
	bool flip[3];
	flip[0] = false;
	flip[1] = false;
	dfs(1,-1, 0, flip);

	cout<<cnt<<endl;
	for(int i=0; i<cnt; i++){
		cout<<res[i]<<endl;
	}
}