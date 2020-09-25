//cf 706 C: Hard Problem
#include <iostream>
#include <cstring>
using namespace std;
const long long int MAX_INT = 100000000000001;

string rev_str(string a){
	int len = a.length();
	string res = a;
	for(int i=len-1; i>=0; i--){
		res[len-1-i] = a[i];
	}
	return res;
}

int main(){
	int n;
	cin>>n;

	long long int cost[n+1];
	string s[n+1];
	long long int f[n+1][2];
	for(int i=0; i<n; i++){
		f[i][0] = MAX_INT;
		f[i][1] = MAX_INT;
	}

	for(int i=0; i<n; i++){
		cin>>cost[i];
	}
	for(int i=0; i<n; i++){
		cin>>s[i];
	}

	f[0][0] = 0;
	f[0][1] = cost[0];

	for(int i=1; i<n; i++){
		if(s[i].compare(s[i-1])>=0){
			f[i][0] = f[i-1][0];
		}
		if(s[i].compare(rev_str(s[i-1]))>=0){
			f[i][0] = min(f[i][0],f[i-1][1]);
		}
		if(rev_str(s[i]).compare(s[i-1])>=0){
			f[i][1] = f[i-1][0] + cost[i];
		}
		if(rev_str(s[i]).compare(rev_str(s[i-1]))>=0){
			f[i][1] = min(f[i-1][1]+cost[i],f[i][1]);
		}
	}

	long long int res = min(f[n-1][0],f[n-1][1]);
	if(res==MAX_INT){
		cout<<-1<<endl;
	}
	else{
		cout<<res<<endl;
	}
}