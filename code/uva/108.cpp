//UVA 108: Maximum Sum
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;

	int ipt[n*n+1];
	for(int i=0; i<n*n; i++){
		cin>>ipt[i];
	}
	//input reads OK

	int arr[n+1][n+1];
	int res[n+2][n+2];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			arr[i][j] = ipt[i*n+j];
		}
		
	}

	res[1][1] = arr[0][0];
	res[0][0]=0;
	res[0][1]=0;
	res[1][0]=0;
	for(int i=2; i<n+1; i++){
		res[1][i] = res[1][i-1] + arr[0][i-1];
		res[i][1] = res[i-1][1] + arr[i-1][0];
		res[0][i]=0;
		res[i][0]=0;
	}

	for(int i=2; i<n+1; i++){
		for(int j=2; j<n+1; j++){
			res[i][j] = res[i-1][j] + res[i][j-1] + arr[i-1][j-1] - res[i-1][j-1];
		}
	}

	int mx = res[1][1];
	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			for(int i1=0; i1<i; i1++){
				for(int j1=0; j1<j; j1++){
					mx = max(res[i][j] - res[i][j1] - res[i1][j] + res[i1][j1], mx);
				}
			}
		}
	}

	cout<<mx<<endl;

					
}