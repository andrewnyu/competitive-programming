//cf 437B: Child and Set
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	int s,l;
	cin>>s>>l;

	vector <int> res;
	for(int i=int(log(l)/log(2)); i>=0; i--){
		int curr = 1<<i;
		int cb = curr;
		while(s-curr>=0 && cb<=l){
			s-=curr;
			res.push_back(cb);
			//cout<<s<<" "<<curr<<endl;
			cb+=curr<<1;
			if(s==0){
				break;
			}
		}
	}

	if(s>0){
		cout<<-1<<endl;
	}
	else{
		cout<<res.size()<<endl;
		for(int i=0; i<res.size(); i++){
			cout<<res[i]<<" ";
		}		
	}

}