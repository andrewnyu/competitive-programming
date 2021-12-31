//ABC061D - Score Attack
#include <iostream>
#include <vector>
using namespace std;
const long long int MX_INT = -1e13;

struct edge{
	long long int s,v,w;
};

int main(){
	vector <edge> edges;
	int n,m;
	cin>>n>>m;
	long long int d[n+1];

	for(int i=0; i<m; i++){
		long long int s,v,w;
		cin>>s>>v>>w;
		edges.push_back((edge){s-1,v-1,w});
	}

	//bellman-ford
	for(int i=0; i<n; i++){
		d[i] = MX_INT;
	}

	d[0]=0;
	for(int k=0; k<n-1; k++){
		for(int i=0; i<m; i++){
			//cout<<edges[i].s<<" "<<d[edges[i].s]<<endl;
			if(d[edges[i].v]<d[edges[i].s]+edges[i].w){
				d[edges[i].v]=d[edges[i].s]+edges[i].w;
			}
		}
	}

	//Cases to account for (common Bellman-Ford errors)
	//case 1: n is at back of edge array (we wouldnt know there was cycle including it)
	//case 2: n is at the front (would be counted with the && n check)
	//case 3: [important] negative cycle is not in path to n (should not return inf
	bool cycle = false;
	for(int i=0; i<m; i++){
		if(d[edges[i].v]<d[edges[i].s]+edges[i].w){
			d[edges[i].v]=d[edges[i].s]+edges[i].w;
			if(edges[i].v==n-1){
				cycle=true;
			}
		}
	}

	if(cycle){
		cout<<"inf"<<endl;
	}
	else{
		cout<<d[n-1]<<endl;
	}
}