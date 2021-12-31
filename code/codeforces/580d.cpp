//CF 580D: Kefa and Dishes
#include <iostream>
#include <algorithm>
using namespace std;
const long long int INT_MX = -36000000001;

long long int a[20];
long long int c[20][20];
long long int dp[20][20];
//dp[i][j]
//i - ith (max m) dish, j - index of last dish
long long int e[20][1LL<<19];
//dp[i][j][mask]

int main(){
	int n,m,k;
	cin>>n>>m>>k;

	long long int nmask = (1LL<<(n-1))|((1LL<<(n-1))-1);
	//cout<<nmask<<endl;

	//init
	for(int i=0; i<max(m,n); i++){
		for(int j=0; j<max(m,n); j++){
			dp[i][j] = INT_MX;
			c[i][j]=0;
		}
	}

	for(int j=0; j<max(m,n); j++){
		for(int mask=0; mask<=nmask; mask++){
			e[j][mask] = INT_MX;
		}
	}


	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<k; i++){
		int x,y,z;
		cin>>x>>y>>z;
		c[x-1][y-1]=z;
	}


	//base case
	long long int res = a[0];
	for(int i=0; i<n; i++){
		long long int cmask = 1LL<<i;
		dp[0][i] = a[i];
		e[i][cmask] = a[i];
		res = max(a[i],res);
	}

	//solve
	for(int i=1; i<m; i++){
		for(int j=0; j<n; j++){
			long long int cmask = 1LL<<j;
			for(int mask=(1LL<<i)-1; mask<=nmask; mask++){
				//cout<<cmask<<" "<<mask<<endl;
				if(!(cmask&mask) && (__builtin_popcount(mask)==i)){
					long long int nwmask = (cmask|mask);
					//cout<<j<<" "<<nwmask<<" "<<e[j][nwmask]<<endl;
					long long int curr = 0;
					while((1LL<<curr)<=mask){
						if(j!=curr){
							e[j][nwmask] = max(e[j][nwmask],e[curr][mask]+a[j]+c[curr][j]);
						}
						curr+=1;
					}

					if(__builtin_popcount(mask)==m-1){
						//cout<<j<<" "<<j1<<" "<<nwmask<<" "<<e[j][nwmask]<<endl;
						res=max(res,e[j][nwmask]);
					}
				}
			}
		}
	}


	cout<<res<<endl;
}