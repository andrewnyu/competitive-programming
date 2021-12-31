//ABC163E: Active Infants
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(pair <long long int, long long int> p1, pair <long long int, long long int> p2){
	return p1.first>p2.first;
}

int main(){
	int n;
	cin>>n;

	vector < pair<long long int, long long int> > arr;
	long long int dp[n+2][n+2] = {0};

	for(int i=0; i<n; i++){
		long long int current;
		cin>>current;
		arr.push_back(make_pair(current,i));
	}
	sort(arr.begin(), arr.end(), compare);

	dp[0][0] = (n-1-arr[0].second)*arr[0].first;
	dp[0][1] = (arr[0].second)*arr[0].first;

	for(int i=1; i<n; i++){
		for(int j=0; j<=i+1; j++){
			if(j==0){
				dp[i][j] = dp[i-1][j]+arr[i].first*abs(n-1-i-arr[i].second);
			}
			else if(j<=i){
				dp[i][j] = max(dp[i-1][j-1]+arr[i].first*abs(arr[i].second-j+1), 
					dp[i-1][j]+arr[i].first*abs(n-1-(i-j)-arr[i].second));
			}
			else{
				dp[i][j] = dp[i-1][j-1] + arr[i].first*abs(arr[i].second-j+1);
			}
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}

	long long int res = 0;
	for(int i=0; i<=n+1; i++){
		//cout<<dp[n-1][i]<<" "<<i<<endl;
		res = max(res, dp[n-1][i]);
	}
	cout<<res<<endl;


}