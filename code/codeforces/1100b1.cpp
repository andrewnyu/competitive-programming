//CF 1100B: Build a Contest
//Alternate solution using understanding of Amortized Analysis
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;

	int frq[n+1]={0};
	int cnt=0; //unique elements
	for(int i=0; i<m; i++){
		int a;
		cin>>a;
		frq[a]+=1;
		if(frq[a]==1){
			cnt+=1;
		}

		if(cnt==n){
			cout<<1;
			for(int j=1; j<=n; j++){
				frq[j]-=1;
				if(frq[j]==0){
					cnt-=1;
				}
			}
		}
		else{
			cout<<0;
		}
	}

}