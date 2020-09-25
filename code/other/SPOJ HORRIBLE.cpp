#include <iostream>
using namespace std;
const int MAXN = 100000;
long long int n, st[MAXN*4+1],flag[MAXN*4+1];
bool lazy[MAXN*4+1];

void pull(int p){
	st[p] = st[p*2] + st[p*2+1];
}
void push(int p, int l, int r){
	if(lazy[p]){
		lazy[p] = false;
		st[p] += ((r-l+1)*flag[p]);
		if(l!=r){
			lazy[p*2] = lazy[p*2+1] = true;
			flag[p*2] += flag[p];
			flag[p*2+1] += flag[p];
		}
		flag[p]=0;
	}
}

void build(long long int arr[], int p=1, int l=0, int r=n-1){
	lazy[p]=false;
	flag[p]=0;
	if(l==r){
		st[p]=arr[l];
	}
	else{
		int m = (l+r)/2;
		build(arr, p*2, l, m);
		build(arr,p*2+1, m+1, r);
		pull(p);
	}
}

void update(int a, int b, int val, int p=1, int l=0, int r=n-1){
	push(p, l,r);
	if(b<l || r<a){
		return;
	}
	if(a<=l && r<=b){
		flag[p]=val;
		lazy[p]=true;
		push(p,l,r);
		return;
	}

	int m=(l+r)/2;
	update(a,b,val,p*2,l,m);
	update(a,b,val,p*2+1,m+1,r);
	pull(p);
}

long long int query(int a, int b, int p=1, int l=0, int r=n-1){
	push(p,l,r);
	//cout<<l<<" "<<r<<" "<<st[p]<<endl;
	if(b<l || r<a){
		return 0;
	}
	if(a<=l && r<=b){
		return st[p];
	}
	int m = (l+r)/2;
	long long int left = query(a,b,p*2,l,m);
	long long int right = query(a,b,p*2+1,m+1,r);
	pull(p);
	return left + right;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int c;
		cin>>n>>c;
		long long int arr[n+1];
		
		for(int i=0; i<n; i++){
			arr[i]=0;
		}
		build(arr);

		for(int i=0; i<c; i++){
			int op,p,q,v;
			cin>>op;
			if(op==0){
				cin>>p>>q>>v;
				update(p-1,q-1,v);
			}
			else{
				cin>>p>>q;
				long long int res = query(p-1,q-1); 
				cout<<res<<endl;
			}
		}

	}
}