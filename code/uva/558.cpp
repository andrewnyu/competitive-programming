//uva 558 wormholes
//is there a negative cycle in the graph?
#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 1000;
const int mx = 1000001;
long long int dist[MAXV];

struct edge{
	int s,d,w;
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0; i<n; i++){
			dist[i] = mx;
		}

		vector <edge> edges;
		for(int i=0; i<m; i++){
			int a,b,c;
			cin>>a>>b>>c;
			edges.push_back((edge){a,b,c});
		}

		dist[0] = 0; //base case
		for(int i=0; i<n-1; i++){
			for(int j=0; j<m; j++){
				int s = edges[j].s;
				int d = edges[j].d;
				int w = edges[j].w;
				if(dist[s]+w<dist[d]){
					dist[d] = dist[s]+w;
				}	
			}
		}
		//check for negative cycles
		//if algo does not find optimal solution (then its cycle) via correctness proof
		bool cycle = false;
		for(int i=0; i<m; i++){
			if(dist[edges[i].s]+edges[i].w < dist[edges[i].d]){
				cycle = true;
			}
		}

		if(cycle){
			cout<<"possible"<<endl;
		}
		else{
			cout<<"not possible"<<endl;
		}

	}
}