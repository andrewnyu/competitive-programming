//CF 75D: Big Maximum Sum
#include <iostream>
#include <vector>
using namespace std;
const long long int INT_MN = -25*1e10 + 1;

struct sa{
	long long int left, right, all, arrmax;
};

int main(){
	int n,m;
	cin>>n>>m;

	vector <sa> arr;
	for(int i=0; i<n; i++){
		int l;
		cin>>l;

		arr.push_back((sa) {INT_MN,INT_MN,0, INT_MN});

		vector <long long int> carr;
		long long int csum = INT_MN;
		for(int j=0; j<l; j++){
			int cval;
			cin>>cval;

			carr.push_back(cval);
			arr[i].all+=cval;

			if(cval>cval + csum){
				csum=cval;
			}
			else{
				csum+=cval;
			}
			arr[i].arrmax = max(csum, arr[i].arrmax);
		}

		csum=0;
		for(int j=0; j<carr.size(); j++){
			csum+=carr[j];
			arr[i].left = max(arr[i].left, csum);
		}

		csum=0;
		for(int j=carr.size()-1; j>=0; j--){
			csum+=carr[j];
			arr[i].right = max(arr[i].right, csum);
		}
	}

	vector <int> farr;
	for(int i=0; i<m; i++){
		int cval;
		cin>>cval;
		farr.push_back(cval-1);
	}


	//final solve
	long long int fsum = INT_MN;
	long long int res = INT_MN;
	for(int i=0; i<m; i++){
		res = max(res, max(fsum, fsum+arr[farr[i]].left));

		//corner case of minimum inside array
		res = max(res, arr[farr[i]].arrmax);

		if(arr[farr[i]].right > arr[farr[i]].all + fsum){
			fsum = arr[farr[i]].right;
		}
		else{
			fsum+=arr[farr[i]].all;
		}
	}

	cout<<res<<endl;
}