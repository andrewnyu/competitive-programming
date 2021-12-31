//ABC 171D: Replacing
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
	long long int cs=0;
	map <int,int> mp;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		cs+=a;
		mp[a]+=1;
	}

	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		int b,c;
		cin>>b>>c;
		cs+=((c-b)*mp[b]);
		mp[c] += mp[b];
		mp[b] = 0;
		cout<<cs<<endl;
	}
}