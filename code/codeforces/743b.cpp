//743B: Chloe and Sequence
#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

long long int solve(long long int n, long long int k){
	if(n==1){
		return 1;
	}
	else{
		long long int mid = 2LL<<(n-2);
		//cout<<mid<<endl;
		if(k==mid){
			return n;
		}
		else{
			return solve(n-1,max(k,mid)-min(k,mid));
		}
	}
}

int main(){
	long long int n,k;
	cin>>n>>k;

	long long int res = solve(n,k);
	cout<<res<<endl;

}