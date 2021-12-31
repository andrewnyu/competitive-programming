//CF 269B: Greenhouse Effect
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	int dp[m+1][n+1];
	for(int i=0; i<=m; i++){
		for(int j=0; j<n; j++){
			dp[i][j] = n+1;
		}
	}

	int arr[n+1];
	for(int i=0; i<n; i++){
		double b;
		cin>>arr[i]>>b;
	}

	for(int i=0; i<arr[0]; i++){
		dp[i][0]=1;
	}
	dp[arr[0]][0]=0;
	int mx = arr[0];

	for(int i=1; i<n; i++){
		mx = max(mx, arr[i]);
		for(int j=0; j<arr[i]; j++){
			//kadto sa likod
			dp[j][i] = dp[j][i-1]+1;
		}
		for(int j=0; j<=arr[i]; j++){
			dp[arr[i]][i] = min(dp[arr[i]][i], dp[j][i-1]);
		}
		for(int j=arr[i]+1; j<=mx; j++){
			//kadto sa una
			dp[j][i] = dp[j][i-1]+1;
		}
	}

	int res = dp[m][n-1];
	for(int i=0; i<=m; i++){
		//cout<<dp[i][n-1]<<endl;
		res = min(res, dp[i][n-1]);
	}

	cout<<res<<endl;
}