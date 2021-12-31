//CF 474D: Flowers
#include <iostream>
using namespace std;
const long long int M = 1e9+7;
int t,k,a,b;
long long int dp[100001];
long long int cum[100001];

long long int solve(int n){
	if(dp[n]!=-1){
		return dp[n];
	}
	else if(n<k){
		return dp[n]=1;
	}
	else if(n==k){
		return dp[n]=2;
	}
	else{
		return dp[n]=(solve(n-1)+solve(n-k))%M;
	}
}

long long int cumsolve(int n){
	if(cum[n]!=-1){
		return cum[n];
	}
	else if(n==0){
		return cum[n]=0;
	}
	else{
		return cum[n] = (solve(n) + cumsolve(n-1))%M;
	}
}

int main(){

	for(int i=0; i<=100000; i++){dp[i]=-1; cum[i]=-1;}


	cin>>t>>k;
	for(int i=0; i<t; i++){
		cin>>a>>b;
		
		long long int res=0;
		res = (M+(cumsolve(b) - cumsolve(a-1)))%M;

		cout<<res<<endl;
	}
}