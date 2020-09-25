//cf 380C: Sereja and Brackets
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 1000000;

struct sq{
	int res=0;
	int left=0,right=0;
};

sq a[MAXV+1];
sq t[2*MAXV+1];

void build(int v, int tl, int tr){
	if(tl==tr){
		t[v]=a[tl];
	}
	else{
		int mid = (tl+tr)/2;
		int lv = v+1;
		int rv = v+2*(mid-tl+1);
		
		build(lv, tl, mid);
		build(rv, mid+1,tr);

		int inc = min(t[lv].right,t[rv].left);
		t[v].res = t[lv].res + t[rv].res + 2*inc;
		t[v].left = t[lv].left + t[rv].left - inc;
		t[v].right = t[lv].right + t[rv].right - inc;
	}
}

sq query(int v, int tl, int tr, int l, int r){
	if(l>r){
		sq empty;
		return empty;
	}
	else if(tl==l && tr==r){
		return t[v];
	}
	else{
		int mid = (tl+tr)/2;
		int lv = v+1;
		int rv = v+2*(mid-tl+1);

		sq lt = query(lv,tl,mid,l,min(mid,r));
		sq rt = query(rv,mid+1,tr,max(l,mid+1),r);

		sq ans;
		int inc = min(lt.right, rt.left);
		ans.res = lt.res + rt.res + 2*inc;
		ans.left = lt.left + rt.left - inc;
		ans.right = lt.right + rt.right - inc;
		return ans;
	}
}

int main(){
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0; i<n; i++){
		if(s[i]==')'){
			a[i].left=1;
		}
		else{
			a[i].right=1;
		}
	}
	build(1,0,n-1);

	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		int ql,qr;
		cin>>ql>>qr;

		sq ans = query(1,0,n-1,ql-1,qr-1);
		cout<<ans.res<<endl;
	}


}