#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 5001;
long long int dp[MAXV][MAXV];
long long int arr[MAXV];
long long int sm[MAXV];
int n,m,k;

//maximal amount of ith segment at pos j
long long int solve(int i, int j){
	if(i<0 || j<0){
		return 0;
	}
	else if(dp[i][j]!=-1){
		return dp[i][j];
	}
	else{
		dp[i][j] = max(solve(i,j-1),solve(i-1,j-m)+sm[j]);
		return dp[i][j];
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sm[i] = 0;

		for(int j=0; j<k; j++){
			dp[j][i] = -1;
		}
	}

	for(int i=0; i<n-m+1; i++){
		for(int j=i; j<i+m; j++){
			sm[i]+=arr[j];
		}
	}

	long long int ans = solve(k-1,n-m);
	cout<<ans<<endl;

}