#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
	int n,m,h;
	double invProb = 1; 
	cin>>n>>m>>h;
	int s[1001];
	int total = 0;
	for(int i=1; i<=m; i++){
		cin>>s[i];
		total += s[i];
	}
 
	int k = s[h]; //people in Herr Wafa's department
	int others = total - k;
	total --; //remove Herr Wafa
 
	if(total < n-1){
		cout<<-1<<endl;
	}
	else if(others + 1 < n){
		cout<<1<<endl;
	}
 
	else {
		for(int i=0; i<n-1; i++){
			//i iterations
			invProb *= ((double)others/(double)total);
			others--;
			total--;
		}
		cout<<1-invProb<<endl; 
	}
 
 
 
 
}