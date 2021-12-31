//ABC 185C Duodecim Ferra
#include <iostream>
using namespace std;

long long int comb[201][22];

long long int solve(int n, int r){
	if(comb[n][r]!=-1){
		return comb[n][r];
	}
	else{
		comb[n][r] = solve(n-1, r) + solve(n-1, r-1);
		return comb[n][r];
	}
}

int main(){
	int l;
	cin>>l;
	for(int i=0; i<=l; i++){
		for(int j=1; j<=11; j++){
			comb[i][j]=-1;
		}
		comb[i][0] = 1;
	}

	long long int res = solve(l-1,11);
	cout<<res<<endl;

}