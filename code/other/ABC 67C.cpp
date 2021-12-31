//ABC 67C: Factors of Factorial
#include <iostream>
#include <cmath>
using namespace std;
const long long int M = 1e9+7;

int main(){
	int n;
	cin>>n;

	bool prime[n+1];
	for(int i=2; i<=n; i++){
		prime[i]=true;
	}

	for(int i=2; i<=int(sqrt(n))+1; i++){
		if(prime[i]){
			int num = i*i;
			while(num<=n){
				prime[num]=false;
				num+=i;
			}
		}
	}

	//formula -> n!-> p1^k1*p2^k2... and num of divisors = (k1+1)*(k2+1)..
	long long int res=1; //sum of all exponents
	for(int i=2; i<=n; i++){
		if(prime[i]){
			int num=i;
			int k=0;
			while(num<=n){
				k+=(n/num);
				num*=i;
			}
			//cout<<i<<" "<<k<<endl;
			res = res*(k+1)%M;
		}
	}

	cout<<res<<endl;


}