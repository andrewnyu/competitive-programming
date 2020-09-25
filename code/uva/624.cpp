//UVA 624: CD
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

long long int res = 0;
string residx;
vector <int> a;
int n;
void solve(string mask, long long int val, int l){
	if (val<=n && val>res){
		res=val;
		residx = mask;
	}
	
	if (val<n && l<a.size()){
		solve(to_string(a[l])+" "+mask, val+a[l], l+1);
		solve(mask, val, l+1);
	}
}

int main(){
	int result=0;
	ios::sync_with_stdio(false);
	int al;
	while(scanf("%d %d", &n, &al)!=EOF){
		a.clear();
		res=0;
		residx="";
		for(int i=0; i<al; i++){
			int c;
			scanf("%d",&c);
			a.push_back(c);
		}

		solve("",0,0);
		cout<<residx<<"sum:"<<res<<endl;
	}
}
