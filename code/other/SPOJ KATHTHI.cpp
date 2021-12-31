//SPOJ KATHTHI - KATHTHI
#include <iostream>
#include <deque>
using namespace std;
const int MAXV = 1000;

char g[MAXV+1][MAXV+1];
long long int d[MAXV+1][MAXV+1];
int r,c; //needed for bounds

struct node{
	int x,y;
	long long int w;
};

deque <node> q;
void check(int x, int y, long long int w, char src){
	if(x>=0 && x<r && y>=0 && y<c){
		if(src==g[x][y] && w<d[x][y]){
			d[x][y]=w;
			q.push_front((node){x,y,d[x][y]});
		}
		else if(src!=g[x][y] && w+1<d[x][y]){
			d[x][y]=w+1;
			q.push_back((node){x,y,d[x][y]});
		}
	}
}

void bfs01(int x, int y){
	d[x][y]=0;
	q.clear();
	q.push_front((node){x,y,0});

	while(!q.empty()){
		node curr = q.front();
		x = curr.x;
		y = curr.y;
		long long int w = curr.w;
		q.pop_front();

		check(x+1, y, w, g[x][y]);
		check(x-1, y, w, g[x][y]);
		check(x, y+1, w, g[x][y]);
		check(x, y-1, w, g[x][y]);

	}	
}

void init(){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			d[i][j] = MAXV*MAXV+1;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>r>>c;
		init();
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cin>>g[i][j];
			}
		}

		bfs01(0,0);
		cout<<d[r-1][c-1]<<endl;

	}
}