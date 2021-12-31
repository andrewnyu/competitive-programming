//CF 166E: Tetrahedron
#include <iostream>
using namespace std;
const long long int M = 1e9+7;

long long int dp[(int)1e7+2];

int main(){
	int n;
	cin>>n;
	dp[1]=0; dp[2]=3;
	for(int i=3; i<=n; i++){dp[i]=((3*dp[i-2])%M + (2*dp[i-1])%M)%M;}
	cout<<dp[n]<<endl;
}