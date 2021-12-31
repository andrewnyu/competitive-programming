//CF1263C: Everyone is a Winner!
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		long long int n;
		cin>>n;

		vector <long long int> res;
		res.clear();
		res.push_back(0);
		int lst=1;
		int k=n;

		while(k>=1){
			//cout<<k<<endl;
			res.push_back(floor(n/k));

			lst=floor(n/k);
			k=floor(n/(lst+1));
		}

		cout<<res.size()<<endl;
		for(int i=0; i<res.size(); i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
}