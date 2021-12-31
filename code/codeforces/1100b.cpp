//CF 1100B: Build a Contest
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	int maxv = max(n,m);

	int arr[maxv+1];
	int frq[maxv+1]={0};
	for(int i=0; i<m; i++){
		cin>>arr[i];
		frq[arr[i]]+=1;
		arr[i]=frq[arr[i]];
	}

	int cnt[maxv+1]={0};
	int idx=1;
	for(int i=0; i<m; i++){
		cnt[arr[i]]+=1;
		if(cnt[idx]==n){
			cout<<1;
			idx+=1;
		}
		else{
			cout<<0;
		}
	}
}