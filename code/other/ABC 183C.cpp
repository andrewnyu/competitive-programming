//ABC 183C: Travel
#include <iostream>
#include <vector>
using namespace std;

long long int t[9][9];
long long int k;
long long int cnt = 0;
int n;

void solve(vector <int> vs, int lst, long long int cost){
	//cout<<vs.size()<<" "<<lst<<" "<<cost<<endl;
	bool ok[9];
	for(int i=0; i<n; i++){ok[i]=false;}
	for(int i=0; i<vs.size(); i++){
		ok[vs[i]]=true;
	}

	for(int i=0; i<n; i++){
		if(!ok[i]){
			vs.push_back(i);
			solve(vs, i, cost+t[lst][i]);
			vs.pop_back();
		}
	}

	if(vs.size()==n && cost==k-t[lst][0]){
		cnt+=1;
	}
}

int main(){

	cin>>n>>k;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>t[i][j];
		}
	}

	vector <int> start;
	start.push_back(0);
	solve(start,0,0);

	cout<<cnt<<endl;
}