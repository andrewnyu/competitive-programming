//SPOJ: Hotels Along The Croatian Coast
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	deque <int> dq;
	long long int res=0;
	long long int curr=0;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;

		while(curr+a>m){
			curr-=dq.front();
			dq.pop_front();
		}
		curr+=a;
		dq.push_back(a);
		
		res = max(res,curr);
	}

	cout<<res<<endl;
}