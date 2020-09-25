#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector <int> pos (9);
int mx;
void solve(vector <int> arr){
	if(arr.size()==8){
		int diff = 0;
		for(int i=0; i<arr.size(); i++){
			if(arr[i]+1!=pos[i]){
				diff++;
			}
		}
		if(diff<mx){
			mx = diff;
		}
	}

	else if(arr.size()<8){
		int n = arr.size();
		for(int i=0; i<8; i++){
			bool valid = true;
			for(int j=0; j<arr.size(); j++){
				if(abs(i-arr[j])==abs(n-j)){
					valid = false;
				}
				else if(i==arr[j]){
					valid = false;
				}
			}
			if(valid){
				arr.push_back(i);
				solve(arr);
				arr.erase(arr.end()-1);
			}
		}
	}
}

int main(){
	int test = 0;
	while(cin>>pos[0]){
		for(int i=1; i<8; i++){
			cin>>pos[i];
		}
		vector <int> ans;
		ans.clear();
		mx = 8;
		solve(ans);

		test++;
		cout<<"Case "<<test<<": "<<mx<<endl;
	}

	
}