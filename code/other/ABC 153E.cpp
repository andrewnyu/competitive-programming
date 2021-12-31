//ABC 153E: Crested Ibis vs Monster
#include <iostream>
#include <algorithm>
using namespace std;
const long long int INT_MX = 1e8+1;

int main(){
	long long int h,n;
	cin>>h>>n;

	long long int a[n+1], b[n+1];
	long long int dp[h+1];

	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0; i<h; i++){dp[i]=INT_MX;}

	dp[h] = 0;
	for(int i=0; i<n; i++){
		for(int j=h; j>0; j--){
			int nxt = max(j-a[i],0LL);
			dp[nxt] = min(dp[nxt], dp[j]+b[i]);
		}
	}

	cout<<dp[0]<<endl;

}