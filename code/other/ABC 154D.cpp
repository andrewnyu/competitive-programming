//ABC 153D Caracal vs Monster
#include <iostream>
#include <cmath>
using namespace std;

long long int solve(long long int h){
	if(h==1){
		return 1;
	}
	else{
		return 2*solve(floor(h/2))+1;
	}
}

int main(){
	long long int h;
	cin>>h;
	long long int res = solve(h);
	cout<<res<<endl;
}