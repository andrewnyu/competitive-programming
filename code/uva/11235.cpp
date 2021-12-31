//uva 11235: frequent values
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int MAXV = 100000;
int a[MAXV+1];
int t[4*MAXV+1];
map <int,int> start;
map <int,int> last;

void build(int v, int tl, int tr){
	if(tl==tr){
		t[v]=1;
	}
	else{
		int tm = (tl+tr)/2;
		build(v*2, tl,tm);
		build(v*2+1,tm+1,tr);
		int left = t[v*2];
		int right = t[v*2+1];
		int mid = min(last[a[tm]],tr)-max(start[a[tm]],tl)+1;

		t[v] = max(left,max(right,mid));
	}
}

int query(int v, int tl, int tr, int l, int r){
	if(l>r){
		return 0;
	}
	if(tl==l && tr==r){
		return t[v];
	}
	else{
		int tm = (tl+tr)/2;
		int left = query(v*2, tl, tm,l,min(tm,r));
		int right = query(v*2+1,tm+1,tr,max(l,tm+1),r);
		int mid = min(last[a[tm]],r)-max(start[a[tm]],l)+1;
		
		return max(left,max(right,mid));
	}
}


int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,q;
	while(cin>>n && n!=0){
		start.clear();
		last.clear();
		cin>>q;

		for(int i=0; i<n; i++){
			cin>>a[i];
			if(start.find(a[i])==start.end()){
				start[a[i]]=i;
			}
			last[a[i]]=i;
		}

		build(1,0,n-1);
		for(int i=0; i<q; i++){
			int l,r;
			cin>>l>>r;
			int res=query(1,0,n-1,l-1,r-1);
			cout<<res<<endl;
		}

	}
}