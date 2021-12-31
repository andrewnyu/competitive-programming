//UVA 441: Lotto
#include <iostream>
#include <vector>
using namespace std;
int s[15];
int k;

void backtrack(vector <int> res, int j){
	if(res.size()==6){
		for(int i=0; i<5; i++){
			cout<<res[i]<<" ";
		}
		cout<<res[5];
		cout<<endl;
	}
	else{
		for(int i=j+1; i<k; i++){
			res.push_back(s[i]);
			backtrack(res,i);
			res.erase(res.end()-1);
		}
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	bool start = true;
	while(cin>>k && k!=0){
		if(!start){
			cout<<endl;
		}
		start = false;
		for(int i=0; i<k; i++){
			cin>>s[i];
		}
		vector <int> res;
		backtrack(res, -1);
	}
}