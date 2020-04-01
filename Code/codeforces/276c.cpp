#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;

	vector <long long int> arr;
	vector <long long int> num_q; 

	int a; 
	for(int i=0; i<n; i++){
		cin>>a;
		arr.push_back(a);
		num_q.push_back(0); 
	}

	int l,r;
	for(int i=0; i<q; i++){
		cin>>l>>r;

		num_q[l-1] +=1;

		if(r!=n){
			num_q[r]-=1;
		}
	}

	for(int i=1; i<n; i++){
		num_q[i] += num_q[i-1];
	}

	sort(num_q.begin(), num_q.end());
	sort(arr.begin(), arr.end());

	long long int sum = 0;
	for(int i=0; i<n; i++){
		sum += (arr[i]*num_q[i]);
	}


	cout<<sum<<endl;
}