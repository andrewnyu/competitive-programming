//ABC 126E 1 or 2
#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 1e5;

struct graph{
	vector <int> *edges[MAXV+1];
};

bool ok[MAXV+1];

void dfs(int v, graph *g){
	ok[v] = true;
	for(int i=0; i<(*g->edges[v]).size(); i++){
		int next = (*g->edges[v])[i];
		if(!ok[next]){
			dfs(next, g);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	graph *g = new graph;

	for(int i=0; i<n; i++){
		g->edges[i] = new vector<int>;
		ok[i] = false;
	}

	for(int i=0; i<m; i++){
		int x,y,z;
		cin>>x>>y>>z;

		(*g->edges[x-1]).push_back(y-1);
		(*g->edges[y-1]).push_back(x-1);
	}

	int cnt = 0;
	for(int i=0; i<n; i++){
		if(!ok[i]){
			//cout<<i<<endl;
			cnt+=1;
			dfs(i, g);
		}
	}

	cout<<cnt<<endl;

}