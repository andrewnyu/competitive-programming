//uva 11631 Dark Roads
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 200000;
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
int find_set(int a){
	if(a==parent[a]){
		return a;
	}
	else{
		parent[a] = find_set(parent[a]);
		return parent[a];
	}
}

int mx;
void union_set(int a, int b){
	//assumes find_set !=and a,b are already heads
	//parent[a] = a
	if(size[a]<size[b]){
		parent[b] = parent[a];
		size[b]+=size[a];
	}
	else{
		parent[a] = parent[b];
		size[a]+=size[b];
	}
}




int main(){
	int n,m;
	while(scanf("%d %d", &m, &n) && n+m!=0){
		//init
		mx = 0;
		for(int i=0; i<m; i++){
			parent[i] = i;
			size[i] = 1;
		}

		vector <edge*> g;
		for(int i=0; i<n; i++){
			edge *e = new edge;
			cin>>e->s>>e->d>>e->w;
			g.push_back(e);
		}

		sort(g.begin(), g.end(), compare);
		int ans=0;
			for(int i=0; i<n; i++){
				if(find_set(g[i]->s)!=find_set(g[i]->d)){
					union_set(find_set(g[i]->s),find_set(g[i]->d));
				}
				else{
					ans+=g[i]->w;
				}
			}

		cout<<ans<<endl;
	}
}