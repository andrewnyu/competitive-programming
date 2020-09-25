//cf 455a
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 100000;
long long int arr[MAXV+1];
long long int dp[MAXV+1][2];

int main(){
	int n;
	for(int i=0; i<=MAXV; i++){
		arr[i]=0;
		dp[i][0]=0;
		dp[i][1]=0;
	}

	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		arr[a]+=a;
	}

	dp[1][0] = 0;
	dp[1][1] = arr[1];

	for(int i=1; i<MAXV+1; i++){
		dp[i][1] = dp[i-1][0]+arr[i];
		dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
	}

	long long int ans = max(dp[MAXV][1],dp[MAXV][0]);
	cout<<ans<<endl;
}