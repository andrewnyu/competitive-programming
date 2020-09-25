//uva 12532: Interval Product
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXV = 100000;
int n,k;
int bs;
int block[MAXV+2];
int zero[MAXV+2];
int arr[MAXV+2];

void update(int x, int w){
	if(w!=arr[x]){
		if(w==0){
			zero[x/bs]++;
			arr[x] = w;
		}
		else if(arr[x]==0){
			zero[x/bs]--;
			arr[x] = w;
			block[x/bs]*=w;
		}
		else{
			arr[x] = w;
			block[x/bs]*=-1;
		}
	}
}

int solve(int l, int r){
	int res = 1;
	int leftr = min(l+bs-l%bs,r);
	for(int i=l; i<leftr; i++){
		res*=arr[i];
	}
	for(int i=r; i>=max(leftr,r-r%bs); i--){
		res*=arr[i];
	}
	for(int i=l/bs+1; i<r/bs; i++){
		if(zero[i]>0){
			res=0;
		}
		else{
			res*=block[i];
		}
	}
	return res;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%d %d",&n, &k)==2){
		bs = ceil(sqrt(n));
		for(int i=0; i<=(n-1)/bs; i++){
			block[i] = 1;
			zero[i] = 0;
		}
		for(int i=0; i<n; i++){
			cin>>arr[i];
			if(arr[i]==0){
				zero[i/bs]++;
			}
			else if(arr[i]<0){
				block[i/bs]*=-1;
				arr[i] = -1;
			}
			else{
				arr[i]=1;
			}
		}

		char ans[k+1];
		int idx = 0;
		for(int i=0; i<k; i++){
			char c;
			int l,r;
			cin>>c>>l>>r;
			if(c=='C'){
				int temp = 1;
				if(r==0){
					temp = 0;
				}
				else if(r<0){
					temp = -1;
				}
				update(l-1,temp);
			}
			else{
				int temp = solve(l-1, r-1);
				if(temp==0){
					ans[idx]='0';
				}
				else if(temp<0){
					ans[idx]='-';
				}
				else{
					ans[idx]='+';
				}
				idx++;
			}
		}

		for(int i=0; i<idx; i++){
			cout<<ans[i];
		}
		cout<<endl;

	}
}