//uva 10557: XYZZY
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long int inf = 10000;
struct edge{
	int s,d;
};


int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int n;
	while(cin>>n && n!=-1){
		bool ok[n] = {false};
		long long int val[n];
		long long int path[n] = {0};

		for(int i=0; i<n; i++){
			path[i] = 0;
			ok[i] = false;
		}

		vector <edge> edges;
		for(int i=0; i<n; i++){
			int a,k;
			cin>>val[i]>>k;
			for(int j=0; j<k; j++){
				cin>>a;
				edges.push_back((edge){i,a-1});
			}
		}
		//belmans for to detect negative cycles
		ok[0] = true;
		path[0] = 100;
		for(int i=0; i<n-1; i++){
			for(int j=0; j<edges.size(); j++){
				int s = edges[j].s;
				int d = edges[j].d;
				if(ok[s] && path[s] + val[d] > 0){
					if(!ok[d] || path[d] < path[s] + val[d]){
						path[d] = path[s] + val[d];
						ok[d] = true;
					}
				}
			}
		}
		//flag all errors as being the nodes of negative cycles
		//kung maka sulod ka di, essentially ang health mo infinite na
		bool cycle[n] = {false};
		for(int i=0; i<edges.size(); i++){
			if(path[edges[i].s] + val[edges[i].d] > path[edges[i].d]){
				//cycle[edges[i].s] = true;
				cycle[edges[i].d] = true;
			}
		}

		for(int i=0; i<n; i++){
			if(cycle[i]){
				val[i] = inf;
			}
		}

		//reset visited and path and check if we can reach n-1
		for(int i=0; i<n; i++){
			path[i] = 0;
			ok[i] = false;
		}

		
		ok[0] = true;
		path[0] = 100;
		for(int i=0; i<n-1; i++){
			for(int j=0; j<edges.size(); j++){
				int s = edges[j].s;
				int d = edges[j].d;
				if(ok[s] && path[s] + val[d] > 0){
					if(!ok[d] || path[d] < path[s] + val[d]){
						path[d] = path[s] + val[d];
						ok[d] = true;
					}
				}
			}
		}
		
		if(ok[n-1]){
			cout<<"winnable"<<endl;
		}
		else{
			cout<<"hopeless"<<endl;
		}

	}
}