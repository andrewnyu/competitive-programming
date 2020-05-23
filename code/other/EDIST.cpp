//SPOJ EDIST
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXV = 2001;
int dp[MAXV][MAXV];
string a,b;

int solve(int i, int j){
	if(dp[i][j]==-1){
		if(i==0 || j==0){
			dp[i][j] = abs(i-j);
		}
		else if(a[i-1]==b[j-1]){
			dp[i][j] = solve(i-1,j-1);
		}	
		else{
			dp[i][j] = min(solve(i,j-1)+1,solve(i-1,j)+1);
			dp[i][j] = min(dp[i][j], solve(i-1,j-1)+1);
		}
		return dp[i][j];
	}
	else{
		return dp[i][j];
	}

}

void init(int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dp[i][j] = -1;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		init(a.length()+1, b.length()+1);
		cout<<solve(a.length(), b.length())<<endl;	
	}


}