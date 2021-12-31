//CF 520B: Two Buttons
#include <iostream>
#include <queue>
using namespace std;

int n,m;
bool ok[20002];
int d[20002];
void bfs(int v){
	ok[v]=true;
	d[v]=0;
	queue <int> q;
	q.push(v);
	while(!q.empty()){
		v = q.front();
		q.pop();
		if(v==m){
			while(!q.empty()){
				q.pop();
			}
			break;
		}
		if(v<m && !ok[v*2]){
			ok[v*2]=true;
			d[v*2]=d[v]+1;
			q.push(v*2);
		}
		if(v>1 && !ok[v-1]){
			ok[v-1]=true;
			d[v-1]=d[v]+1;
			q.push(v-1);
		}
	}
}


int main(){
	cin>>n>>m;
	bfs(n);

	int res = d[m];
	cout<<res<<endl;
}