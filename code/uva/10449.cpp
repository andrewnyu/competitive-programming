#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long int INF = 1600000000;
const int MAXV = 200;

long long int dist(int a, int b){
	return (b-a)*(b-a)*(b-a);
}

struct edge{
	long long int s,d,w;
};

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	int n,t;
	t=1;
	while(scanf("%d",&n)==1){
		vector <edge> g;
		g.clear();
		vector <int> edges[n];
		int val[n];
		for(int i=0; i<n; i++){
			cin>>val[i];
			edges[i].clear();
		}
		int r;
		cin>>r;
		for(int i=0; i<r; i++){
			int a,b;
			cin>>a>>b;
			g.push_back((edge){a-1,b-1,dist(val[a-1],val[b-1])});
			edges[a-1].push_back(b-1);
		}

		long long int path[n];
		bool ok[n];
		bool neg[n];
		for(int i=0; i<n; i++){
			ok[i] = false;
			neg[i] = false;
			path[i] = INF;
		}

		path[0] = 0;
		ok[0] = true;
		for(int i=0; i<n-1; i++){
			for(int j=0; j<g.size(); j++){
				long long int s = g[j].s;
				long long int d = g[j].d;
				long long int w = g[j].w;
				if(ok[s] && path[s]+w<path[d]){
					ok[d] = true;
					path[d] = path[s] + w;
				}
			}
		}

		//all nodes you can reach by a cycle are automatically -1
		//find negative cycles and dfs/bfs from them
		for(int i=0; i<g.size(); i++){
			if(path[g[i].s] + g[i].w < path[g[i].d]){
				if(ok[g[i].s]&&!neg[g[i].d]){
					queue <int> q;
					q.push(g[i].d);
					while(!q.empty()){
						int v = q.front();
						q.pop();
						for(int j=0; j<edges[v].size(); j++){
							if(!neg[edges[v][j]]){
								neg[edges[v][j]]=true;
								q.push(edges[v][j]);
								}
							}
						}
					}

				}
			}
		


		int q;
		cin>>q;
		cout<<"Set #"<<t<<endl;
		t++;
		for(int i=0; i<q; i++){
			int a;
			cin>>a;
			if(a>n){
				cout<<"?"<<endl;
			}
			else if(path[a-1]==INF){
				cout<<"?"<<endl;
			}
			else if(neg[a-1]){
				cout<<"?"<<endl;
			}
			else if(path[a-1]<3){
				cout<<"?"<<endl;
			}
			else{
				cout<<path[a-1]<<endl;
			}
		}
	}	
}