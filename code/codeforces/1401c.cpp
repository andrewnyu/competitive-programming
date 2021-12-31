#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long int gcd(long long int a, long long int b){
	if(a==0){
		return b;
	}
	else{
		return gcd(b%a,a);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		vector <long long int> a;
		vector <long long int> b;
		long long int v;
		for(int i=0; i<n; i++){
			long long int c;
			cin>>c;
			a.push_back(c);
			b.push_back(c);
			if(i==0){
				v=c;
			}
			v = min(v,c);
		}

		sort(a.begin(),a.end());
		bool pos = true;
		for(int i=0; i<n; i++){
			if((a[i]!=b[i]) && (b[i]%v!=0)){
				pos=false;
			}
		}

		if(pos){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}