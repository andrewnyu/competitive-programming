//UVA12032: The Monkey and the Oiled Bamboo
#include <iostream>
using namespace std;

int arr[100002];
int n;

int bs(int l, int r){
	if(l>=r){
		return r;
	}
	else{
		int mid = (l+r)/2;
		bool ok = true;
		int k = mid;
		//cout<<k<<endl;
		for(int i=0; i<=n; i++){
			if(arr[i]-arr[i-1]>k){
				ok = false;
				break;
			}
			else if(arr[i]-arr[i-1]==k){
				k-=1;
			}
		}

		if(ok){
			//cout<<l<<" "<<r<<endl;
			return bs(l, mid);
		}
		else{
			return bs(mid+1, r);
		}
	}
}


int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		cin>>n;

		int mx=0;
		arr[0]=0;
		for(int i=1; i<=n; i++){
			cin>>arr[i];
			mx = max(mx, arr[i]-arr[i-1]);
		}

		int res = bs(1, mx+n+1);
		cout<<"Case "<<test<<": "<<res<<endl;
	}	
}