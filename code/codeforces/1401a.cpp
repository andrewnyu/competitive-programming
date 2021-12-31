#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		
		//dist from origin
		int res = max(0,k-n);
		res += (n+res+k)%2;
		cout<<res<<endl;
	}
}