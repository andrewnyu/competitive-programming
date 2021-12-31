//CF 30C: Shooting Gallery
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXV = 1000;
struct target{
	double x,y,t,p;
};

bool compare(target a, target b){
	return  a.t<b.t;
};

vector <target> g;
double d[MAXV+1];


int main(){
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		g.push_back((target){0,0,0,0});
		cin>>g[i].x>>g[i].y>>g[i].t>>g[i].p;
	}

	sort(g.begin(), g.end(), compare);
	//initialize d
	for(int i=0; i<n; i++){d[i]=g[i].p;}

	//dp
	double res=d[0];
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			double dist = sqrt(pow(g[i].x-g[j].x,2)+pow(g[i].y-g[j].y,2));
			if(g[j].t+dist<=g[i].t){
				d[i] = max(d[j]+g[i].p, d[i]);
			}
		}
		res = max(res, d[i]);
	}

	cout<<fixed<<setprecision(8)<<res<<endl;
}