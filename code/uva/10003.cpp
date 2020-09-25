//UVA 10003: Cutting Sticks
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000;
const int INT_MX = 50001;
int dp[N+2][N+2];
int a[52];
int n; //size of a

int solve(int l, int r){
	if(dp[l][r]!=-1){
		return dp[l][r];
	}
	else{

		dp[l][r] = INT_MX;
		bool base = true;
		for(int i=0; i<n; i++){
			if(a[i]>l && a[i]<r){
				base = false;
				int curr = r-l+ solve(l,a[i]) + solve(a[i],r);
				dp[l][r] = min(curr,dp[l][r]);
			}
		}

		if(base){
			dp[l][r]=0;
		}
			
		return dp[l][r];
	}
}

int main(){
	//freopen("input.txt", "r",stdin);;
	//freopen("output.txt","w",stdout);
	int l;
	while(cin>>l && l!=0){
		cin>>n;
		for(int i=0; i<l+1; i++){
			for(int j=0; j<l+1; j++){
				dp[i][j] = -1;
			}
		}

		for(int i=0; i<n; i++){
			cin>>a[i];
			//a[i]-=1;
		}

		int res = solve(0,l);
		cout<<"The minimum cutting is "<<res<<"."<<endl;
	}
}