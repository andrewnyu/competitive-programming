//CF545C: Woodcutters
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	int t[n+1];
	int h[n+1];

	for(int i=0; i<n; i++){
		cin>>t[i]>>h[i];
	}

	int res=2;
	if(n==1){
		res=1;
	}
	for(int i=1; i<n-1; i++){
		if(t[i]-h[i]>t[i-1]){
			res+=1;
		}
		else if(t[i]+h[i]<t[i+1]){
			res+=1;
			t[i]+=h[i];
		}
	}

	cout<<res<<endl;
}