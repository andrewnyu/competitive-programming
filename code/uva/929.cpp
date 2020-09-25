#include <iostream>
#include <queue>
using namespace std;
const int MAXV = 1000;
const long long int MX = 2147483647;
long long int g[MAXV][MAXV];
long long int path[MAXV*MAXV+1];
bool ok[MAXV*MAXV+1];
int n,m;
int tn(int x, int y){
	//row x column, y
	return y+m*x;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>g[i][j];
				path[tn(i,j)]=MX;
				ok[tn(i,j)]=false;
			}
		}

		priority_queue <pair<int,int>>pq;
		pq.push(make_pair(g[0][0],0));
		ok[0]=true;
		path[0] = g[0][0];
		while(!pq.empty()){
			int curr = pq.top().second;
			pq.pop();
			int x = curr/m;
			int y = curr%m;
			if(x+1<n){
				int c = tn(x+1,y);
				long long int dist = path[curr] + g[x+1][y];
				if(dist<path[c] && !ok[c]){
					ok[c] = true;
					path[c] = dist;
					pq.push(make_pair(-dist,c));
				}
			}
			if(y+1<m){
				int c = tn(x,y+1);
				long long int dist = path[curr] + g[x][y+1];
				if(dist<path[c] && !ok[c]){
					ok[c] = true;
					path[c] = dist;
					pq.push(make_pair(-dist,c));
				}
			}
			if(x-1>=0){
				int c = tn(x-1,y);
				long long int dist = path[curr] + g[x-1][y];
				if(dist<path[c] && !ok[c]){
					ok[c] = true;
					path[c] = dist;
					pq.push(make_pair(-dist,c));
				}
			}
			if(y-1>=0){
				int c = tn(x,y-1);
				long long int dist = path[curr] + g[x][y-1];
				if(dist<path[c] && !ok[c]){
					ok[c] = true;
					path[c] = dist;
					pq.push(make_pair(-dist,c));
				}
			}
		}

		long long int ans = path[tn(n-1,m-1)];
		cout<<ans<<endl;
	}

}