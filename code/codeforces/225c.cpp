//CF 225C: Barcode
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;

	int arr[m+1][2];
	for(int i=0; i<m; i++){arr[i][0]=0; arr[i][1]=n;}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char px;
			cin>>px;
			if(px=='#'){
				arr[j][0]+=1;
				arr[j][1]-=1;
			}
		}
	} 

	//solve
	//dp struct
	int dp[m+1][m+2][2];
	for(int i=0; i<m; i++){
		for(int j=0; j<=y; j++){
			dp[i][j][0] = m*n+1;
			dp[i][j][1] = m*n+1;
		}
	}


	dp[0][1][0] = arr[0][1];
	dp[0][1][1] = arr[0][0];

	for(int i=1; i<m; i++){
		for(int j=1; j<min(y,i+1); j++){
			dp[i][j+1][0]=dp[i-1][j][0]+arr[i][1];
			dp[i][j+1][1]=dp[i-1][j][1]+arr[i][0];
		}

		dp[i][1][0] = dp[i-1][x][1] + arr[i][1];
		dp[i][1][1] = dp[i-1][x][0] + arr[i][0];
		for(int j=x+1; j<=min(y,i); j++){
			dp[i][1][0]=min(dp[i][1][0], dp[i-1][j][1] + arr[i][1]);
			dp[i][1][1]=min(dp[i][1][1], dp[i-1][j][0] + arr[i][0]);
		}	
	}

	//it is guaranteed we will have a valid solution
	int res=m*n+1;
	for(int i=x; i<=y; i++){
		res = min(res, dp[m-1][i][0]);
		res = min(res, dp[m-1][i][1]);
	}
	cout<<res<<endl;

}