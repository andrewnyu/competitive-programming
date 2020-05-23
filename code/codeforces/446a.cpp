//DZY Loves Sequences
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	long long int arr[n+1][3];
	for(int i=0; i<n; i++){
		cin>>arr[i][0];
		arr[i][1] = arr[i][0];
		arr[i][2] = arr[i][0];
	}

	//dp[i][k] longest until i with or w/o patatwad k
	//k=1 incremented, k=2 reduced preceeding
	int dp[n+1][3] = {1};
	int mx = 1;
	for(int i=1; i<n; i++){
		if(arr[i][0]>arr[i-1][0]){
			dp[i][0] = dp[i-1][0] + 1;

			for(int j=1; j<3; j++){
				if(arr[i][0]>arr[i-1][j]){
					dp[i][j] = dp[i-1][j]+1;
				}
			}
		}
		else{
			dp[i][0] = 1;

			dp[i][1] = dp[i-1][0] + 1;
			arr[i][1] = arr[i-1][0] + 1;

			if(dp[i-1][0]==1){
				dp[i][2] = dp[i-1][0] + 1;
			}
			else if(arr[i][0]-1>arr[i-2][0]){
				dp[i][2] = dp[i-1][0] + 1;
			}
			else{
				dp[i][2] = 2;
			}
		}

		for(int j=0; j<=2; j++){
			if(dp[i][j]>mx){
				mx = dp[i][j];
			}
		}
		
	}

	cout<<mx<<endl;
}