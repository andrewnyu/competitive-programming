//Codeforces 2B: Least Round Way
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXV = 1000000;
const long long int INIT = 10000000;
//0-two, 1-five
long long int mat[MAXV+1][2];
long long int d[MAXV+1][2];
int parent[MAXV+1][2];
int n;

int power(long long int num, int base){
	int cnt = 0;
	while(num%base==0){
		num/=base;
		cnt++;
	}
	return cnt;
}

void djk(int start, int k){
	d[start][k] = mat[start][k];

	for(int i=1; i<n*n; i++){
		if(i-n>=0){
			if(mat[i][k]+d[i-n][k]<d[i][k]){
				d[i][k] = mat[i][k] + d[i-n][k];
				parent[i][k] = i-n;
			}
		}
		if(i%n>0){
			if(mat[i][k]+d[i-1][k]<d[i][k]){
				d[i][k] = mat[i][k] + d[i-1][k];
				parent[i][k] = i-1;
			}
		}
	}
}

int main(){
	cin>>n;
	bool corner = false;
	int cloc = -1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			d[i*n+j][0] = INIT;
			d[i*n+j][1] = INIT;
			mat[i*n+j][0] = 0;
			mat[i*n+j][1] = 0;
			long long int a;
			cin>>a;
			if(a==0){
				cloc = i*n + j;
				corner = true;
				a = 10;
			}

			mat[i*n+j][0] = power(a,2);
			mat[i*n+j][1] = power(a,5);
		}
	}

	djk(0,0);
	djk(0,1);

	long long int res = min(d[n*n-1][0],d[n*n-1][1]);

	//corner case
	if(res>1 && corner){
		cout<<1<<endl;
		//force pass 0
		int p =0;
		for(int i=0; i<cloc%n; i++){
			cout<<"R";
		}
		for(int i=0; i<cloc/n; i++){
			cout<<"D";
		}
		for(int i=0; i<n-1-cloc%n; i++){
			cout<<"R";
		}
		for(int i=0; i<n-1-cloc/n; i++){
			cout<<"D";
		}
	}

	else{
		int mo = 0;
		if(res==d[n*n-1][1]){
			mo=1;
		}

		cout<<res<<endl;
		char seq[2*n];
		int idx=0;
		int p = n*n-1;
		while(p!=0){
			if(parent[p][mo]==p-n){
				seq[idx]='D';
			}
			else{
				seq[idx]='R';
			}
			idx++;
			p = parent[p][mo];
		}

		for(int i=0; i<2*(n-1); i++){
			cout<<seq[2*(n-1)-1-i];
		}

	}

}