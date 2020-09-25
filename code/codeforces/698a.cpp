//cf698a Vacations
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	int dp[n+1][2] = {0};

	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	if(arr[0]==0){
		dp[0][1]+=1;
		dp[0][0]+=1;
	}
	else if(arr[0]==1){
		dp[0][1]+=1;
	}
	else if(arr[0]==2){
		dp[0][0]+=1;
	}

	for(int i=1; i<n; i++){
		if(arr[i]==0){
			dp[i][0] = min(dp[i-1][0],dp[i-1][1])+1;
			dp[i][1] = dp[i][0];
		}
		else if(arr[i]==1){
			dp[i][0] = dp[i-1][1];
			dp[i][1] = min(dp[i-1][1],dp[i-1][0])+1;
		}
		else if(arr[i]==2){
			dp[i][1] = dp[i-1][0];
			dp[i][0] = min(dp[i-1][1],dp[i-1][0])+1;			
		}
		else{
			dp[i][1] = dp[i-1][0];
			dp[i][0] = dp[i-1][1];
		}
	}

	int res = min(dp[n-1][0],dp[n-1][1]);
	cout<<res<<endl;
}