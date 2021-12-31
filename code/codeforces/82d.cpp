//cf 82D: Two Out of Three
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long int INT_MX = 1000000001;

//dp[n][k] cheapest way to get to n na ang k pinalabas
long long int dp[1001][1001];
int p[1001][1001];
long long int a[1001];

vector < pair<int,int> > ans;
void print_sol(int n, int k){
	int nk;
	if(k<n-1){
		nk = k;
		ans.push_back(make_pair(n,n+1));
	}
	else if(k==n-1){
		nk = p[n][n-1];
		ans.push_back(make_pair(p[n][n-1]+1,n+1));
	}
	else{
		nk = p[n][n];
		ans.push_back(make_pair(p[n][n]+1,n));		
	}

	if(n>2){
		print_sol(n-2,nk);
	}
}

int main(){
	int n;
	cin>>n;
	ans.clear();
	for(int i=0; i<n; i++){
		cin>>a[i];

		for(int j=0; j<n; j++){
			dp[i][j] = INT_MX;
		}
	}

	dp[2][0] = max(a[1],a[2]);
	dp[2][1] = max(a[0],a[2]);
	dp[2][2] = max(a[0],a[1]);

	for(int i=3; i<n-(1-n%2); i++){
		for(int j=0; j<i-1; j++){
			dp[i][j] = dp[i-2][j] + max(a[i],a[i-1]);
			p[i][j] = i-2;
			if(max(a[i],a[j])+dp[i-2][j]<dp[i][i-1]){
				dp[i][i-1] = max(a[i],a[j])+dp[i-2][j];
				p[i][i-1] = j;
			}
			if(max(a[i-1],a[j])+dp[i-2][j]<dp[i][i]){
				dp[i][i] = max(a[i-1],a[j])+dp[i-2][j];
				p[i][i] = j;
			}
		}
	}

	//solve
	if(n==1){
		cout<<a[0]<<endl;
		cout<<1<<endl;
	}
	else if(n==2){
		cout<<max(a[0],a[1])<<endl;
		cout<<1<<" "<<2<<endl;
	}
	else if(n%2!=0){
		long long int res = INT_MX;
		int l1;
		for(int i=0; i<n; i++){
			if(dp[n-1][i]+a[i]<res){
				res = dp[n-1][i]+a[i];
				l1=i;				
			}

		}
		cout<<res<<endl;
		//cout<<p[n-1][l1]<<endl;
		print_sol(n-1,l1);
		for(int i=ans.size()-1; i>=0; i--){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
		cout<<l1+1<<endl;
	}
	else{
		long long int res = INT_MX;
		int l1, r1;
		for(int i=0; i<n; i++){
			if(dp[n-2][i]+max(a[i],a[n-1])<res){
				res = dp[n-2][i]+max(a[i],a[n-1]);
				l1 = i, r1 = n-1;
			}
		}
		cout<<res<<endl;
		//cout<<p[n-1][n-1]<<endl;
		print_sol(n-2,l1);
		for(int i=ans.size()-1; i>=0; i--){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
		cout<<l1+1<<" "<<r1+1<<endl;
	}

}