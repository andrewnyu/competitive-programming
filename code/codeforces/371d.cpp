#include <iostream>
using namespace std;
const int MAXV = 200001;
int cap[MAXV];
int cont[MAXV];
int tail[MAXV];
int n;

int find_tail(int k){
	if(k>=n){
		return n;
		//floor
	}
	else if(tail[k]==k){
		return k;
	}
	else{
		tail[k] = find_tail(tail[k]);
		return tail[k];
	}
}

void fill_vessel(int k, int w){
	int kt = find_tail(k);
	if(kt<n){
		if(cont[kt]+w>=cap[kt]){
			tail[kt] = find_tail(kt+1);
			int bal = w-cap[kt]+cont[kt];
			cont[kt] = cap[kt];
			fill_vessel(find_tail(kt+1),bal);
		}
		else{
			cont[kt]+=w;
		}
	}
}

int main(){
	cin>>n;

	for(int i=0; i<n; i++){
		cin>>cap[i];
		cont[i] = 0;
		tail[i] = i;
	}

	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		int type;
		cin>>type;
		if(type==1){
			int a,b;
			cin>>a>>b;
			fill_vessel(a-1,b);
		}
		else{
			int a;
			cin>>a;
			cout<<cont[a-1]<<endl;
		}
	}

}