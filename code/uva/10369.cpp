//uva 10369 Arctic Network
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXV = 500;
double x[MAXV];
double y[MAXV];
bool ok[MAXV];
double mx[MAXV];

struct edge{
	int x,y;
	double w;
};

double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


bool compare(edge a, edge b){
	return a.w<b.w;
}


int parent[MAXV];
int size[MAXV];
int find_set(int a){
	if(parent[a]==a){
		return a;
	}
	else{
		parent[a] = find_set(parent[a]);
		return parent[a];
	}
}

void union_set(int a, int b){
	if(size[a]<size[b]){
		parent[a] = b;
		size[b]+=size[a];		
	}
	else{
		parent[b] = a;
		size[a]+=size[b];				
	}

}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;

	while(t--){
		int s,p;
		cin>>s>>p;
		for(int i=0; i<p; i++){
			cin>>x[i]>>y[i];

			ok[i] = false;
			parent[i] = i;
			size[i] = 1;
			mx[i] = 0;
		}

		vector <edge> g;
		g.clear();
		for(int i=0; i<p-1; i++){
			for(int j=i+1; j<p; j++){
				double curr_d = dist(x[i], y[i], x[j], y[j]);
				edge e;
				e.x = i;
				e.y = j;
				e.w = curr_d;
				g.push_back(e);
			}
		}

		sort(g.begin(), g.end(), compare);
		int cnt = 0;
		double ans = 0;
		for(int i=0; i<g.size(); i++){
			if(find_set(g[i].x)!=find_set(g[i].y)){
				int a = g[i].x;
				int b = g[i].y;
				union_set(find_set(a), find_set(b));
				if(cnt < p-s){
					cnt ++;
					ans = g[i].w;
				}
				else{
					break;
				}
			}
		}

		cout<<fixed<<setprecision(2)<<ans<<endl;

	}
	
}