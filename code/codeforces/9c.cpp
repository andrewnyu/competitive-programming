//CF 9C: Hexadecimal Numbers
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin>>n;

	int base = 1LL<<9;
	int cnt=0;
	for(int i=1; i<=base; i++){
		int num=0;
		for(int j=0; j<=9; j++){
			if(i&(1LL<<j)){
				num+=pow(10,j);
			}
		}

		if(num<=n){
			cnt+=1;
		}
		else{
			break;
		}
	}
	cout<<cnt<<endl;
}