//CF 329B: Biridian Forest
#include <iostream>
#include <queue>
using namespace std;
const int MAXV = 1001;
int r,c;
int d[MAXV+1][MAXV+1];
int v[MAXV+1][MAXV+1];
bool ok[MAXV+1][MAXV+1];
bool mk[MAXV+1][MAXV+1];

void bfs(int x, int y){
	queue <pair<int,int>> q;
	d[x][y]=0;
	ok[x][y]=true;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if(cx-1>=0){
			if(!ok[cx-1][cy]){
				q.push(make_pair(cx-1,cy));
				d[cx-1][cy] = d[cx][cy]+1;
				ok[cx-1][cy]=true;
			}
		}
		if(cy-1>=0){
			if(!ok[cx][cy-1]){
				q.push(make_pair(cx,cy-1));
				d[cx][cy-1] = d[cx][cy]+1;
				ok[cx][cy-1]=true;
			}
		}
		if(cx+1<r){
			if(!ok[cx+1][cy]){
				q.push(make_pair(cx+1,cy));
				d[cx+1][cy] = d[cx][cy]+1;
				ok[cx+1][cy]=true;
			}
		}
		if(cy+1<c){
			if(!ok[cx][cy+1]){
				q.push(make_pair(cx,cy+1));
				d[cx][cy+1] = d[cx][cy]+1;
				ok[cx][cy+1]=true;
			}
		}
	}
}


int main(){
	cin>>r>>c;
	int sx,sy,ex,ey;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			char a;
			cin>>a;
			if(a=='S'){
				sx=i;
				sy=j;
				ok[i][j]=false;
				mk[i][j]=false;
			}
			else if(a=='E'){
				ex=i;
				ey=j;
				ok[i][j]=false;
				mk[i][j]=false;
			}
			else if(a!='T'){
				v[i][j] = (a-'0');
				ok[i][j]=false;
				mk[i][j]=true;
			}
			else{
				ok[i][j]=true;
				mk[i][j]=false;
				//tree
			}
		}
	}

	bfs(ex,ey);
	int res=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(ok[i][j] && mk[i][j] && (d[i][j]<=d[sx][sy])){
				res+=v[i][j];
			}
		}
	}

	cout<<res<<endl;
}