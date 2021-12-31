//cf 193b: maximum absurdity
#include <iostream>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	long long int arr[n+1];
	long long int s[n+1];
	long long int dp[n+1];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(i==0){
			s[i]=arr[i];
		}
		else{
			s[i] = s[i-1]+arr[i];
		}
	}

	dp[0] = s[k-1];
	int minl[n+1];
	minl[0]=0;
	for(int i=1; i<n-k+1; i++){
		dp[i] = s[i+k-1]-s[i-1];
		if(dp[i]>dp[minl[i-1]]){
			minl[i] = i;
		}
		else{
			minl[i] = minl[i-1];
		}
	}

	int l=0;
	int r=k;
	for(int i=k+1; i<n-k+1; i++){
		if(dp[i]>dp[r]){
			r=i;
			if(dp[minl[i-k]]>dp[l]){
				l=minl[i-k];
			}
		}
		else if(dp[i]+dp[minl[i-k]]>dp[r]+dp[l]){
			r=i;
			l=minl[i-k];
		}
	}
	cout<<l+1<<" "<<r+1<<endl;
}