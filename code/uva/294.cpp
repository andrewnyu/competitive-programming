//UVA 294: Divisors
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		//U-V<10000 (we can store all values)
		int l,u;
		cin>>l>>u;


		int divisors[u-l+2] = {0};
		int mx = 0;
		int mx_int = 0;
		for (int i = 1; i <= sqrt(u); ++i){
			int idx = (l+(i-l%i));
			if(l%i==0){idx=l;}
			 for (int j = idx; j <= u; j += i){
			 	if(j>=l && j<=u){
			  		
			  		divisors[j-l]+=2;

			  		if(j/i<=sqrt(u)){
			  			//counting sqrt twice
			 			divisors[j-l]-=1;
			 		}

			  		if(divisors[j-l]>mx || (divisors[j-l]==mx && j<mx_int)){
			  			mx = divisors[j-l];
			  			mx_int = j;
			  		}
			 	}
			 }
		}

		 cout<<"Between "<<l<<" and "<<u<<", "<<mx_int<<" has a maximum of "<<mx<<" divisors."<<endl;
	}
}