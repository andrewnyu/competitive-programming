#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a0,a1,a2;
		int b0,b1,b2;
		cin>>a0>>a1>>a2;
		cin>>b0>>b1>>b2;

		int res = 2*min(b1,a2);

		//step 1: maximize profit
		int ra2 = max(0, a2-b1);
		int rb1 = max(0, b1-a2);

		//step 2: minimize cost
		int rb2 = max(0, b2-ra2);

		//ste 3: further minimize cost
		int ra1 = max(0, a1-rb1);
		rb2 = max(0, rb2-a0);

		//calculate cost
		res-=2*rb2;

		cout<<res<<endl;

	}
}