//CF52C: Circular RMQ
#include <iostream>
#include <string>
using namespace std;
const int N = 200000;
const long long int INF = 2000000000000000001;
long long int n, m,st[N*4], flag[N*4]; bool lazy[N*4];
void pull(int p) {
	st[p] = min(st[p*2], st[p*2 + 1]);
}
void push(int p, int L, int R) { 
	// push flag down
	if (lazy[p]) {
		lazy[p] = false;
		st[p] += flag[p]; // or st[p] += flag, depends
		if (L != R) {
			lazy[p*2] = lazy[p*2 + 1] = true;
			flag[p*2] += flag[p];
			flag[p*2+1] += flag[p];
		}
		flag[p]=0;
	}
} 

// build segment tree from array arr[]
void build(int arr[], int p=1, int L=0, int R=n-1) {
	flag[p]=0;
	lazy[p] = false;
	if (L == R) {
		st[p] = arr[L]; 
		return;
	}
	int M = (L + R) / 2;
	build(arr, p*2, L, M);
	build(arr, p*2 + 1, M + 1, R);
	pull(p);
} 

// set arr[a...b] = value
void update(int a, int b, int value, int p=1, int L=0, int R=n-1) {
	push(p, L, R);
	if(b<L || R<a){
		return;
	}
	if(a <= L && b >= R) {
		flag[p] = value; 
		lazy[p] = true;
		push(p, L, R); 
		return; 
	}
	int M = (L + R) / 2;
	update(a, b, value, p*2, L, M);
	update(a, b, value, p*2 + 1, M + 1, R);
	pull(p);
} 

// RANGE QUERY: min[a...b] (modifiable)
long long int query(int a,int b,int p=1, int L=0, int R=n-1) {
	push(p, L, R);
	if (b < L || R < a) return INF;
	if (a <= L && b >= R) return st[p];
	int M = (L + R) / 2;
	long long int left = query(a, b, p*2, L, M);
	long long int right = query(a, b, p*2 + 1, M + 1, R);
	pull(p); 
	return min(left, right); 
}


int main(){
	//cout<<INF<<endl;
	cin>>n;
	int arr[n+1];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	build(arr,1,0,n-1);

	cin>>m;
	cin.clear();
	cin.ignore(10000,'\n');
	for(int i=0; i<m; i++){
		string s;
		getline(cin,s);
		int cnt=0;

		int l,r,v;
		string delimiter = " ";
		s+=delimiter;
		size_t pos = 0;
		std::string token;
		while ((pos = s.find(delimiter)) != std::string::npos) {
		    token = s.substr(0, pos);
		    if(cnt==0){
		    	l=stoi(token);
		    }
		    else if(cnt==1){
		    	r=stoi(token);
		    }
		    else{
		    	v=stoi(token);
		    }
		    cnt+=1;
		    s.erase(0, pos + delimiter.length());
		}


		if(cnt==3){
			if(l>r){
				update(l,n-1,v);
				update(0,r,v);
			}
			else{
				update(l,r,v);
			}
		}
		else{
			long long int res;
			if(l>r){
				res = min(query(l,n-1),query(0,r));
			}
			else{
				res=query(l,r);
			}
			cout<<res<<endl;
		}
	}
	
}