//CF 1311D: Three Integers
#include <iostream>
#include <cmath>
using namespace std;
const int INT_MX = 1e4*3;

int main(){
	int t;
	cin>>t;

	while(t--){
		int a,b,c;
		cin>>a>>b>>c;

		int res = INT_MX;
		int ra, rb, rc;
		for(int i=1; i<=2*a; i++){
			for(int j=i; j<=2*b; j+=i){
				
				int cc = c-c%j;
				if(abs(c-cc)>(j-c%j)){
					cc = c+(j-c%j);
				}

				int cres = abs(a-i) + abs(b-j) + abs(c-cc);
				if(cres<res && j<=cc){
					ra = i;
					rb = j;
					rc = cc;
					res = cres;
				}
			}
		}

		cout<<res<<endl;
		cout<<ra<<" "<<rb<<" "<<rc<<endl; 

	}
}