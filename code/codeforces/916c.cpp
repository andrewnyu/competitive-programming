//cf916 C: Jaime and Interesting Graph
#include <iostream>
#include <cmath>
#include <algorithm>
const int MAXV=100000;
const int MAXP = 10*MAXV+1;
using namespace std;

int main(){
	bool prime[MAXP+1];
	for(int i=2; i<MAXP; i++){
		prime[i] = true;
	}
	for(int i=2; i<=sqrt(MAXP); i++){
		int current = i*i;
		while(current<=MAXP){
			prime[current]=false;
			current+=i;
		}
	}

	int n,m;
	cin>>n>>m;
	//force sp=2 and part of mst
	int lst = 1;
	while(!prime[n-1+lst]){
		lst+=1;
	}

	//print mst
	long long int mst = lst+n-1;
	cout<<2<<" "<<mst<<endl;
	cout<<1<<" "<<n<<" "<<2<<endl;
	if(m>1){
		for(int i=1; i<n-2; i++){
			cout<<i<<" "<<i+1<<" "<<1<<endl;
		}
		cout<<n-2<<" "<<n-1<<" "<<lst<<endl;		
	}


	//print filler nodes
	int rem = m-n+1;
	lst = max(lst,2);
	if(rem){
		cout<<n-1<<" "<<n<<" "<<lst<<endl;
		rem--;
	}

	for(int i=3; i<n; i++){
		if(!rem){
			break;
		}
		cout<<1<<" "<<i<<" "<<lst<<endl;
		rem--;
	}
	for(int i=2; i<=n-2; i++){
		for(int j=i+2; j<=n; j++){
			if(!rem){
				break;
			}
			cout<<i<<" "<<j<<" "<<lst<<endl;
			rem--;
		}
	}

}