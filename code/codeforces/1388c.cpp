//CF 1388C: Uncle Bogdan and Country Happiness
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int MAXV = 100002;


vector <int> g[MAXV+1];

void add_edge(int a, int b){
	g[a].push_back(b);
	g[b].push_back(a);
}

long long int h[MAXV+1];
long long int ch[MAXV+1];
long long int pop[MAXV+1];
long long int cpop[MAXV+1];
bool ok[MAXV+1];
bool pos;

void dfs(int v){
	ok[v]=true;

	for(int i=0; i<g[v].size(); i++){
		if(!ok[g[v][i]]){
			dfs(g[v][i]);
			cpop[v]+=cpop[g[v][i]];
			ch[v]+=h[g[v][i]];
		}

	}

	//principle 1: happiness impossible given traffic
	if(cpop[v]<abs(h[v])){
		pos=false;
	}
	//principle 2: happiness mathematically impossible given traffic
	else if(int(cpop[v]-abs(h[v]))%2!=0){
		pos=false;
	}

}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n,m;
		cin>>n>>m;

		for(int i=0; i<n; i++){
			cin>>pop[i];
			
			//init
			cpop[i]=pop[i];
			ch[i]=0;
			ok[i]=false;
			g[i].clear();
		}

		for(int i=0; i<n; i++){
			cin>>h[i];
		}

		for(int i=0; i<n-1; i++){
			int a,b;
			cin>>a>>b;
			add_edge(a-1,b-1);
		}
		//end of input

		pos=true;
		dfs(0);

		//principle 3 - happiness increased
		for(int i=0; i<n; i++){
			//cout<<i<<": "<<cpop[i]<<" "<<pop[i]<<" "<<ch[i]<<endl;
			if((pop[i]-ch[i]+h[i])/2<0){
				//cout<<i<<endl;
				pos=false;
			}
		}

		if(pos){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}