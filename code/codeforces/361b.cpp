//CF 361B: Levko and Permutation
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;

	vector <int> res;
	int cnt=0;
	bool allgood = true;
	for(int i=2; i<=n; i++){
		if(i<2+k){
			res.push_back(i);
			cnt+=1;
		}
		else{
			allgood = false;
			res.push_back(i+1);
		}
	}

	if(allgood){
		res.insert(res.begin(),1);
	}
	else{
		res.insert(res.begin(),2+k);
		res[n-1] = 1;
	}

	if(cnt<k){
		cout<<-1<<endl;
	}
	else{
		for(int i=0; i<n; i++){
			cout<<res[i]<<" ";
		}
	}

}