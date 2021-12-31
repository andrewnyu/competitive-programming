//ABC 146C: Buy an Integer
#include <iostream>
#include <cmath>
using namespace std;

int num_digts(long long int x){
	int num=0;
	while(x>0){
		num+=1;
		x/=10;
	}
	return num;
}


int main(){
	//we know value is directly related to number of digits
	//hence we can binary search for the maximum number of digits then return floor (X/A)
	long long int a,b,x;
	cin>>a>>b>>x;

	long long int left=0, right=pow(10,9);
	long long int mid=1;
	while(left<right){
		mid = 1+(left+right)/2;
		
		long long int val = a*mid + b*num_digts(mid);

		if(x>=val){
			left = mid;
		}
		else{
			right = mid-1;
		}
	}

	cout<<left<<endl;

}