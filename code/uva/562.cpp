#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//knapsack problem variation: how much can you fill such that <= half
int dp[50002][102];
int coins[102];

void init(int n, int k){
	for(int i=0; i<n; i++){
		for(int j=0; j<=k; j++){
			dp[i][j] = -1;
		}
	}
}
int solve(int n, int k){
	if(dp[n][k]!=-1){
		return dp[n][k];
	}
	else if(n-coins[k]>=0){
		dp[n][k] = max(solve(n-coins[k],k-1)+coins[k],solve(n,k-1));
		return dp[n][k];
	}
	else{
		dp[n][k] = solve(n,k-1);
		return dp[n][k];
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum = 0;
		for(int i=1; i<=n; i++){
			cin>>coins[i];
			sum+=coins[i];
		}

		//base case
		init(sum+1,n);
		for(int i=0; i<sum+1; i++){
			dp[i][0] = 0;
		}

		int val = solve(ceil(sum/2),n);
		int ans = sum - 2*val;
		cout<<ans<<endl;

	}	
}