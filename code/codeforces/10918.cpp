//UVA 10918: Tri Tiling
#include <iostream>
using namespace std;
long long int dp[32][10];

int main(){

	int n;
	while(cin>>n && n!=-1){
		if(n==0){
			cout<<1<<endl;
		}
		else{
			//base case
			for(int i=0; i<8; i++){
				dp[1][i]=0;
			}
			dp[0][0]=0;
			dp[1][1]=1;
			dp[1][4]=1;
			dp[1][7]=1;

			//solve
			for(int i=2; i<=n; i++){
				dp[i][0]=dp[i-1][1] + dp[i-1][4] + dp[i-1][7];
				dp[i][1]=dp[i-1][0]+dp[i-1][6];
				dp[i][4]=dp[i-1][0]+dp[i-1][3];
				dp[i][3]=dp[i-1][4];
				dp[i][6]=dp[i-1][1];
				dp[i][7]=dp[i-1][0];
			}

			cout<<dp[n][0]<<endl;
		}
	}
}