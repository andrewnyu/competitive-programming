//ABC 57D: Maximum Average Sets
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


long long int dpc[51][51]; //stored value of nCr

long long int comb(long long int n, long long int r){
	//cout<<n<<r<<endl;
	if(dpc[n][r]!=-1){
		return dpc[n][r];
	}
	else if(n==0){
		return dpc[n][r]=0;
	}
	else if(r==0){
		return dpc[n][r]=1;
	}
	else if(r==1){
		return dpc[n][r]=n;
	}
	else{
		dpc[n][r] = comb(n-1,r-1) + comb(n-1, r);
		return dpc[n][r];
	}

}

int main(){
	double n,a,b;
	cin>>n>>a>>b;
	
	//init
	for(int i=0; i<=51; i++){for(int j=0; j<=51; j++){dpc[i][j]=-1;}}

	vector <long long int> arr;
	for(int i=0; i<n; i++){
		long long int curr;
		cin>>curr;
		arr.push_back(curr);
	}

	sort(arr.begin(), arr.end());

	//given v are all positive, largest mean will have a numbers
	double res=0;
	bool same = true;
	for(int i=n-1; i>=n-a; i--){
		res+=((double)arr[i]/a);
		if(i!=n-1){
			if(arr[i]!=arr[i+1]){
				same=false;
			}
		}
	}

	long long int mn=arr[n-a];
	long long int rr=0;
	long long int rn=0;

	for(int i=0; i<n; i++){
		if(arr[i]==mn){
			rn+=1;
			if(i>=n-a){
				rr+=1;
			}
		}
	}

	//cout<<rn<<" "<<rr<<endl;

	//regular case
	long long int cnt=1;
	cnt = comb(rn, rr);

	//special case - first a numbers are the same
	int idx=a+1;
	while(same && idx<=b){
		if(arr[n-idx]==mn){
			cnt+=comb(rn, idx);
			idx+=1;
		}
		else{
			same=false;
		}
	}

	//long long int val = comb(50LL,25LL);
	//cout<<val<<endl;
	//cout<<comb(30,12)<<endl;
	//cout<<comb(9,7)<<endl;




	cout<<fixed<<setprecision(7)<<res<<endl;
	cout<<cnt<<endl;
}