//cf 429B: Working Out
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXV = 1000;
int n,m;
long long int f[MAXV+1][MAXV+1][4];
long long int c[MAXV+1][MAXV+1];

void solve(int r1, int c1, int r2, int c2, int k){
	int ri = (r2-r1)/abs(r2-r1);
	int ci = (c2-c1)/abs(c2-c1);
	f[r1][c1][k] = c[r1][c1];

	for(int i=r1; ri*i<=ri*r2; i+=ri){
		for(int j=c1; ci*j<=ci*c2; j+=ci){
			if(i+ri>=0 && i+ri<n){
				if(f[i+ri][j][k]<f[i][j][k]+c[i+ri][j]){
					f[i+ri][j][k]=f[i][j][k]+c[i+ri][j];
				}
			}
			if(j+ci>=0 && j+ci<m){
				if(f[i][j+ci][k]<f[i][j][k]+c[i][j+ci]){
					f[i][j+ci][k]=f[i][j][k]+c[i][j+ci];
				}
			}
		}
	}
}

int main(){
	cin>>n>>m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>c[i][j];
		}
	}

	solve(0,0,n-1,m-1,0);
	solve(n-1,0,0,m-1,1);
	solve(0,m-1,n-1,0,2);
	solve(n-1,m-1,0,0,3);

	long long int res = 0;
	for(int i=1; i<n-1; i++){
		for(int j=1; j<m-1; j++){
			long long int sm1 = f[i-1][j][0] + f[i][j-1][1] + f[i+1][j][3] + f[i][j+1][2];
			long long int sm2 = f[i][j-1][0] + f[i+1][j][1] + f[i][j+1][3] + f[i-1][j][2];

			res = max(res, max(sm1,sm2));
		}
	}

	cout<<res<<endl;
}