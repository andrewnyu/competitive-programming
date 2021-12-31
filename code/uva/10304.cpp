//UVA 10304 - Optimal Binary Search Tree
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long int MX_INT = 250*250*100+1;

long long int dp[252][252];
long long int csum[252];
vector <int> arr;

long long int rsum(int l, int r){
	if(l==0){
		return csum[r];
	}
	else{
		return csum[r] - csum[l-1];
	}
}

long long int lvl_one(int l, int r){
	//cheapest cost of creating a tree at level one from l to r
	if(l<0 || r<0 || l>r){
		return 0;
	}
	else if(dp[l][r]!=MX_INT){
		return dp[l][r];
	}
	else if(l==r){
		dp[l][r] = arr[l];
		return dp[l][r];
	}
	else{
		for(int i=l; i<=r; i++){
			dp[l][r] = min(dp[l][r], rsum(l,r)+lvl_one(l,i-1)+lvl_one(i+1,r));
		}
		return dp[l][r];
	}
}

void init(int n){
	arr.clear();
	for(int i=0; i<n; i++)for(int j=0; j<n; j++){
		dp[i][j]= MX_INT;
		csum[i]=0;
	}
}


int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int n;
	while(cin>>n){
		init(n+1);

		for(int i=0; i<n; i++){
			int a;
			cin>>a;
			arr.push_back(a);

			if(i==0){
				csum[i]=a;
			}
			else{
				csum[i]=a+csum[i-1];
			}
		}

		long long int res = MX_INT;
		for (int i=0; i<n; i++){
			res = min(res, lvl_one(0,i-1) + lvl_one(i+1,n-1));
		}
		
		cout<<res<<endl;
	}
}