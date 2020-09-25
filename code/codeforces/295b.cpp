#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAXV = 500;
long long int d[MAXV+1][MAXV+1];
int mp[MAXV];
 
void ff(int n){
	int k = n-1;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			if(d[mp[k]][mp[i]] > d[mp[k]][mp[j]] + d[mp[j]][mp[i]]){
				d[mp[k]][mp[i]] = d[mp[k]][mp[j]] + d[mp[j]][mp[i]];
			}
			if(d[mp[i]][mp[k]] > d[mp[i]][mp[j]] + d[mp[j]][mp[k]]){
				d[mp[i]][mp[k]] = d[mp[i]][mp[j]] + d[mp[j]][mp[k]];
			}
		}
	} 

	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			if(d[mp[i]][mp[j]] > d[mp[i]][mp[k]] + d[mp[k]][mp[j]]){
				d[mp[i]][mp[j]] = d[mp[i]][mp[k]] + d[mp[k]][mp[j]];
			}
		}
	} 
 
}
 
 
long long int sm(int n){
	long long int sum = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			sum += d[mp[i]][mp[j]];
		}
	}
	return sum;
}
 
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>d[i][j];
		}
	}
 
	int del[n];
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		mp[n-i-1] = a-1;
	}
 
	vector <long long int> ans;
	ans.push_back(0);
	for(int t=2; t<=n; t++){
		ff(t);
		ans.push_back(sm(t));
	}
 
	for(int i=0; i<n; i++){
		cout<<ans[n-1-i]<<" ";
	}
 
}