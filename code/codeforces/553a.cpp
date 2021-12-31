//CF 553A: Kyoya and Colored Balls
#include <iostream>
#include <algorithm>
using namespace std;
const long long int M = 1000000007;

//identity: modInv(a,m) = modPow(a,m-2,m) if m is prime
/*
long long int modComb(int n, int k){
	long long int resn = 1;
	for(int i=max(k,n-k)+1; i<=n; i++){
		resn = (resn*i)%M;
	}

	long long int resd = 1;
	for(int i=1; i<=min(k,n-k); i++){
		resd = (resd*i)%M;
	}

	return (resn/resd);
}
*/

long long int c[1001][1001];
long long int modComb(int n, int k){
	if(c[n][k]!=-1){
		return c[n][k];
	}
	else if(k==0 || k==n){
		c[n][k]=1;
		return c[n][k];
	}
	else if(k==1){
		c[n][k]=n;
		return c[n][k];
	}
	else{
		c[n][k] = (modComb(n-1,k-1) + modComb(n-1,k))%M;
		return c[n][k];
	}
}




int main(){
	int k;
	cin>>k;
	int a[k+1];
	int s[k+1];

	for(int i=0; i<k; i++){
		cin>>a[i];
		if(i==0){
			s[i]=0;
		}
		else{
			s[i]=s[i-1]+a[i-1];
		}
	}

	//init
	for(int i=0; i<=1000; i++){
		for(int j=0; j<=1000; j++){
			c[i][j] = -1;
		}
	}

	long long int dp[k+1];
	dp[0]=1;
	for(int i=1; i<k; i++){
		dp[i] = (dp[i-1]*modComb(s[i]+a[i]-1,a[i]-1))%M;
	}
	cout<<dp[k-1]<<endl;
}