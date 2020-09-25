#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 100001;
struct edge{
	int d;
	long long int w;
};
int n,m,k;
bool b[MAXV];

int main(){
	cin>>n>>m>>k;
	vector <vector <edge> *> g (n+1);
	for(int i=0; i<=n; i++){
		g[i] = new vector<edge>;
		b[i] = false;
	}
	for(int i=0; i<m; i++){
		int a,b;
		long long int c;
		cin>>a>>b>>c;
		(*g[a]).push_back((edge){b,c});
		(*g[b]).push_back((edge){a,c});
	}
	for(int i=0; i<k; i++){
		int a;
		cin>>a;
		b[a] = true;
	}
	long long int mn = INT_MAX;
	for(int i=1; i<=n; i++){
		if(b[i]){
			for(int j=0; j<(*g[i]).size(); j++){
				int curr = (*g[i])[j].d;
				long long int dist = (*g[i])[j].w;
				if(dist<mn && !b[curr]){
					mn = dist;
				}
			}
		}
	}

	if(mn==INT_MAX){
		cout<<-1<<endl;
	}
	else{
		cout<<mn<<endl;
	}
}