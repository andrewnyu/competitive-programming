//UVA 10325: The Lottery
#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}

int main(){
	int n,m;
	int a[17];

	while(scanf("%d %d", &n, &m)==2){
		for(int i=0; i<m; i++){
			cin>>a[i];
		}

		long long int mxc = (1LL<<m)-1;
		long long int res=0;

		for(int i=1; i<=mxc; i++){
			int flip = 1;
			if(__builtin_popcount(i)%2==0){
				flip=-1;
			}
			long long int cd=1;
			for(int j=0; j<m; j++){
				if((1LL<<j)&i){
					cd=cd*a[j]/gcd(cd,a[j]);
				}
			}
			//cout<<res<<" "<<cd<<endl;

			res+=(flip*(n/cd));
		}	

		cout<<n-res<<endl;
	}
}