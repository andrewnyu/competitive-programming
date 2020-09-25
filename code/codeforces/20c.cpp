//with help from successful submissions to fix memory limit problems
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 100001;

struct node{
	int d,w;
};

vector <node> g[MAXV];
int parent[MAXV];
long long int path[MAXV];
bool ok[MAXV];

int main(){
	int n,m;
	cin>>n>>m;

	for(int i=2; i<=n; i++){
		parent[i] = -1;
		path[i]=1000000000000;
		ok[i] = false;
	}
	
	for(int i=0; i<m; i++){
		int a,b,w;
		cin>>a>>b>>w;
		g[a].push_back((node){b,w});
		g[b].push_back((node){a,w});
	}

	priority_queue <pair<int,int>> pq;
	pq.push(make_pair(0,1));
	while(!pq.empty()){
		int y = pq.top().second;
		pq.pop();

		if(ok[y]){
			continue;
		}
		else{
			ok[y] = true;
			vector<node>::iterator it;
			for(it=g[y].begin(); it!=g[y].end(); it++){
				if(path[y]+it->w<path[it->d]){
					parent[it->d] = y;
					pq.push(make_pair(-(path[it->d]=path[y]+it->w),it->d));
				}
			}
		}

	}

	if(parent[n]==-1){
		cout<<-1<<endl;
	}
	else{
		vector <int> ans;
		int a = n;
		while(a!=1){
			ans.push_back(a);
			a = parent[a];
		}
		ans.push_back(1);
		for(int i=ans.size()-1; i>=0; i--){
			cout<<ans[i]<<" ";
		}
		cout<<endl;

	}

	
}