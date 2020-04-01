#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,k,q;
	cin>>n>>k>>q;
	vector <long long int> arr (200001);
	vector <long long int> arr_k (200001);

	for(int i=0; i<200001; i++){
		arr[i] = 0;
		arr_k[i] = 0;
	}

	int a,b;
	for(int i=0; i<n; i++){
		cin>>a>>b;

		arr[a]+=1;

		if(b != 200000){
			arr[b+1]-=1; 
		}
	}

	for(int i=1; i<200001; i++){
		arr[i] += arr[i-1];
		if(arr[i]>=k){
			arr_k[i] ++;
		}
	}


	for(int i=1; i<200001; i++){
		arr_k[i] += arr_k[i-1];
	}

	
	for(int i=0; i<q; i++){
		cin>>a>>b;
		
		if(a>1){
			cout<<arr_k[b] - arr_k[a-1]<<endl;
		}
		else{
			cout<<arr_k[b]<<endl;
		}

	}



	


}