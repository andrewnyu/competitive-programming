//uva 12086 - potentiometers - solved with seg. tree
//code to learn implementation of seg tree
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 200000;
int a[MAXV+1];
long long int t[4*MAXV+1];

void build(int v, int tl, int tr){
	if(tl==tr){
		t[v] = a[tl];
	}
	else{
		int tm = (tr+tl)/2;
		build(2*v, tl, tm);
		build(2*v+1,tm+1,tr);
		t[v] = t[2*v] + t[2*v+1];
	}
}

long long int sum(int v, int tl, int tr, int l, int r){
	if(l>r){
		return 0;
	}
	else if(l==tl && r==tr){
		return t[v];
	}
	
	int tm = (tl+tr)/2;
	return sum(v*2,tl,tm,l,min(r,tm)) 
		+ sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl==tr){
		t[v] = val;
	}
	else{
		int tm = (tl+tr)/2;
		if (pos<=tm){
			update(v*2, tl,tm,pos,val);
		}
		else{
			update(v*2+1,tm+1,tr,pos,val);
		}
		t[v] = t[v*2] + t[v*2+1];
	}
}


int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t=1;
	int n;
	while(cin>>n && n!=0){
		if(t>1){
			cout<<endl;
		}
		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		build(1,0,n-1);

		cout<<"Case "<<t<<":"<<endl;
		t++;
		string c;
		while(cin>>c && c!="END"){
			int a,b;
			cin>>a>>b;

			if(c[0]=='S'){
				update(1,0,n-1,a-1,b);
			}
			else{
				cout<<sum(1,0,n-1,a-1,b-1)<<endl;
			}
		}
	}
}