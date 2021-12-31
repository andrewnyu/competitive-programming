//CF 124B: Permutations
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int nums[10][10];
int n,k;
long long int res=1e8+1;

void swap(int a[], int p1, int p2){
	int temp;
	temp = a[p1];
	a[p1] = a[p2];
	a[p2] = temp;
}

int cnt=0;
void permutation1(int a[], int p) {
    if(p==1){

    	/*
    	for(int i=1; i<=9; i++){
    		cout<<a[i];
    	}
    	cout<<endl;
    	*/

    	cnt+=1;

    	long long int val[n+1];
    	for(int i=0; i<n; i++){

    		val[i]=0;
    		for(int j=0; j<k; j++){
    			val[i]+=(pow(10,k-j-1)*nums[i][a[j]]);
    		}
    	}	


    	long long int mx = val[0];
    	long long int mn = val[0];

    	for(int i=1; i<n; i++){
    		//cout<<val[i]<<endl;
    		mx = max(mx, val[i]);
    		mn = min(mn, val[i]);
    	}

    	res = min(res, mx-mn);

    	return;
    }
    for(int i=0; i<p; i++) {
        swap(a, i, p-1);  // (remove the ith element)
        permutation1(a, p-1);
        swap(a, i, p-1);  // (restore for the next round)
    }
}

int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		for(int j=0; j<k; j++){
			nums[i][j] = (s[j]-'0');
		}
	}

	//solution


	int arr[10] = {0,1,2,3,4,5,6,7,8,9};

	permutation1(arr,k);

	//cout<<cnt<<endl;



	cout<<res<<endl;
}