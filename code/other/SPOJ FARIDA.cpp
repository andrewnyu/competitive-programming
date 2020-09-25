#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		int n;
		cin>>n;
		long long int dp[10001][2]; //dp[i][j] maximum coins from i monsters given j (1 or 0) take from the jth monster
		for(int i=0; i<=n; i++){
			dp[i][1] = 0;
			dp[i][0] = 0;
		}
		long long int coin[n+1];
		for(int i=0; i<n; i++){
			cin>>coin[i];
		}

		//base case
		dp[0][1] = coin[0];
		dp[0][0] = 0;
		for(int i=1; i<n; i++){
			dp[i][1] = coin[i] + dp[i-1][0];
			dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
		}

		long long int ans;
		if(n>0){
			ans = max(dp[n-1][1],dp[n-1][0]);		
		}

		cout<<"Case "<<test<<": "<<ans<<endl;

	}
}