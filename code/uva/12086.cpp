//uva 12086: pentiometers
#include <iostream>
#include <cmath>
using namespace std;
const int MAXV = 200001;
long long int arr[MAXV+2];
long long int block[MAXV+2];
int bs;
int n;

void update(int a, int w){
	block[a/bs]+=(w-arr[a]);
	arr[a] = w;
}

long long int solve(int l, int r){
	long long int res = 0;
	for(int i=l-1; i>=l-l%bs; i--){
		res -= arr[i];
	}
	for(int i=r+1; i<min(r+bs-r%bs,n); i++){
		res -= arr[i];
	}
	for(int i=l/bs; i<r/bs+1; i++){
		res += block[i];
	}
	return res;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int cs=0;
	while(scanf("%d",&n) && n!=0){
		if(cs>0){
			cout<<endl;
		}
		bs = ceil(sqrt(n));
		for(int i=0; i<n; i++){
			scanf("%d",&arr[i]);
			block[i/bs] = 0;
		}

		for(int i=0; i<n; i++){
			block[i/bs]+=arr[i];
		}

		cs++;
		cout<<"Case "<<cs<<":"<<endl;
		string s;
		while(cin>>s){
			if(s[0]=='E'){
				break;
			}
			else if(s[0]=='S'){
				int a,b;
				cin>>a>>b;
				update(a-1,b);
			}
			else{
				int x,y;
				cin>>x>>y;
				cout<<solve(x-1,y-1)<<endl;
			}
		}
	}
}