//778A: String Game
#include <iostream>
using namespace std;
const int MAXV = 200001;

int rm[MAXV+1];
string p,s;

bool is_subseq(string p, string s){
	//check if p is a subsequence of s
	int i1=0;
	int i2=0;
	while(i1<s.length()){
		if(s[i1]==p[i2]){
			i2+=1;
		}
		i1+=1;
	}

	//cout<<p<<" "<<s<<" "<<i2<<endl;

	if(i2==p.length()){
		return true;
	}
	else{
		return false;
	}
}

int bs(int l, int r){
	if(l>=r){
		return l;
	}
	else{
		int mid = 1+(l+r)/2;
		string current = s;
		for(int i=0; i<mid; i++){
			current[rm[i]-1]=' ';
		}

		//cout<<l<<" "<<r<<" "<<current<<endl;

		if(is_subseq(p, current)){
			return bs(mid, r);
		}
		else{
			return bs(l, mid-1);
		}

	}
}


int main(){
	cin>>s>>p;
	for(int i=0; i<s.length(); i++){
		cin>>rm[i];
	}

	int res = bs(0, s.length()-1);
	cout<<res<<endl;
}