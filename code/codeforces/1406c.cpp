//CF 1406C: Link Cut Centroids
#include <iostream>
#include <vector>
using namespace std;

vector <int> centroids;
vector<int> g [100002];
int parent[100002];
int n;
int sz[100002];


void dfs(int v, int prev){
	bool is_centroid = true;
	for(int i=0; i<g[v].size(); i++){
		if(g[v][i]!=prev){
			dfs(g[v][i], v);
			sz[v]+=sz[g[v][i]];

			if(sz[g[v][i]]>(n/2)){
				is_centroid = false;
			}
		}
	}
	if (n-sz[v] > (n/2)){
		is_centroid =false;
	}

	if (is_centroid){
		centroids.push_back(v);
	}

	//cout<<v<<" "<<sz[v]<<endl;
}



int main(){

	int t;
	cin>>t;
	while(t--){
		cin>>n;

		for(int i=0; i<n; i++){
			sz[i]=1;
			g[i].clear();
		}

		centroids.clear();

		for(int i=0; i<n-1; i++){
			int a,b;
			cin>>a>>b;
			g[a-1].push_back(b-1);
			g[b-1].push_back(a-1);
		}

		dfs(0, -1);


		if (centroids.size() == 1) {
		    int c = centroids[0];
		    //no action needed
		    cout<<c+1<<" "<<g[c][0]+1<<endl;
		    cout<<c+1<<" "<<g[c][0]+1<<endl;
		    
		} 
		else if (centroids.size() == 2) {
	        int c1 = centroids[0];
	        int c2 = centroids[1];
	        int bp = -1;
	        for(int i=0; i<g[c1].size(); i++){
	        	if(g[c1][i]!=c2){
	        		bp = g[c1][i];
	        		break;
	        	}
	        }
	        //disconnect from one and add to other
	        cout<<c1+1<<" "<<bp+1<<endl;
		    cout<<c2+1<<" "<<bp+1<<endl;

		}
	}
	
}