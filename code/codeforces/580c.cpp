//CF 580C: Kefa and Park
#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 1e5;

int n,m;
bool cat[MAXV+1];
bool leaf[MAXV+1];
bool ok[MAXV+1];
vector <int> g[MAXV+1];

void dfs(int v, int p, int cc){
	//cout<<v<<" "<<p<<" "<<cc<<endl;
	ok[v] = true;
	for(int i=0; i<g[v].size(); i++){
		int ncc=cc;
		if(g[v][i]!=p){
			if(cat[v] && cat[g[v][i]]){
				//cout<<v<<" "<<g[v][i]<<" "<<cc<<endl;
				ncc+=1;
			}
			else{
				ncc = cat[g[v][i]];
			}
			leaf[v] = false;
			
			if(ncc<=m){
				dfs(g[v][i],v,ncc);
			}
		}
	}
}

int main(){
	cin>>n>>m;

	for(int i=0; i<n; i++){
		cin>>cat[i];
		leaf[i]=true;
		ok[i] = false;
	}

	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}

	leaf[0] = false;
	dfs(0,0,cat[0]);

	int res=0;
	for(int i=0; i<n; i++){
		if(leaf[i] && ok[i]){
			res+=1;
		}
	}

	cout<<res<<endl;

}