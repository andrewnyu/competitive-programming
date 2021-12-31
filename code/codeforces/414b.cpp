//CF 414B: Mashmokh and ACM
#include <iostream>
using namespace std;
const long long int M = 1e9+7;
long long int dp[2003][2003];

int main(){
	int n,k;
	cin>>n>>k;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			dp[i][j] = 0;
		}
	}

	for(int i=1; i<=n; i++){
		dp[i][1]=1;
	}

	for(int i=1; i<k; i++){
		for(int j=1; j<=n; j++){
			for(int j1=j; j1<=n; j1+=j){
				dp[j1][i+1] = (dp[j1][i+1] + dp[j][i])%M;
			}
		}
	}

	long long int res = 0;
	for(int i=1; i<=n; i++){
		res = (res + dp[i][k])%M;
	}

	cout<<res<<endl;

}