//cf 484A
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		long long int l,r;
		cin>>l>>r;
		r++;
		int b=60;
		long long int curr = 1LL<<b;
		while(!((r&curr)&&!(l&curr)) && b>=0){
			b--;
			curr=1LL<<b;
		}
		long long int res = r^curr;
		curr--;
		res = res|curr;
		cout<<res<<endl;
	}
}