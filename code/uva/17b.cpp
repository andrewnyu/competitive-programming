#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 1000;
struct edge{
	int s;
	int d;
	int w;
};

bool compare(edge *a, edge *b){
	return a->w<b->w;
}

int parent[MAXV];
int size[MAXV];
bool ok[MAXV];
int find_set(int a){
	if(parent[a]==a){
		return a;
	}
	else{
		parent[a] = find_set(parent[a]);
		return parent[a];
	}
}

void union_set(int a, int b){
	//already heads of sets
	if(size[a]<size[b]){
		parent[a] = b;
		size[b] += size[a];
	}
	else{
		parent[b] = a;
		size[a] += size[b];
	}
}


int main(){
	int n;
	cin>>n;
	for(int i=1; i<n+1; i++){
		int q;
		cin>>q;
		parent[i] = i;
		size[i] = 1;
		ok[i] = true;
	}
	
	int m;
	cin>>m;
	vector <edge *> g;
	for(int i=0; i<m; i++){
		edge *e = new edge;
		cin>>e->s>>e->d>>e->w;
		g.push_back(e);
	}

	sort(g.begin(), g.end(), compare);
	long long int ans = 0;
	int cnt = 0;
	for(int i=0; i<m; i++){
		if(find_set(g[i]->s)!=find_set(g[i]->d) && ok[g[i]->d]){
			ok[g[i]->d]=false;
			union_set(find_set(g[i]->s), find_set(g[i]->d));
			ans += g[i]->w;
			cnt ++;
		}
	}

	if(cnt==n-1){
		cout<<ans<<endl;
	}
	else{
		cout<<-1<<endl;
	}





}