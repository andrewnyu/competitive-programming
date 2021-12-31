//CF 219D: Choosing Capital for Treeland
#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 200001;

struct ct{
	int dest, dir;
};

vector <ct> g[MAXV+1];
int res[MAXV+1], d[MAXV+1], inv[MAXV+1];
int invsum=0;

void cost(int v, int p){
	for(int i=0; i<g[v].size(); i++){
		if(g[v][i].dest!=p){
			d[g[v][i].dest] = d[v]+1;
			inv[g[v][i].dest] = inv[v] + g[v][i].dir;
			invsum+=g[v][i].dir;
			cost(g[v][i].dest, v);
		}
	}
}

int main(){
	int n;
	cin>>n;

	for(int i=0; i<n; i++){res[i]=0; d[i]=0; inv[i]=0;}
	
	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		g[a-1].push_back((ct){b-1,1});
		g[b-1].push_back((ct){a-1,0});

	}

	cost(0, -1);
	int mres=MAXV;
	for(int i=0; i<n; i++){
		res[i] = ((n-1)-d[i])-(invsum-inv[i])+inv[i];
		mres = min(mres, res[i]);
	}
	

	vector <int> pidx;
	for(int i=0; i<n; i++){
		//cout<<i<<" "<<res[i]<<endl;
		if(res[i]==mres){
			pidx.push_back(i+1);
		}
	}

	cout<<mres<<endl;
	for(int i=0; i<pidx.size(); i++){
		cout<<pidx[i]<<" "; 
	}
}