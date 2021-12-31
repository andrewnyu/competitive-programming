//CF 639A: Bear and Displayed Friends
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	int n,k,q;
	int t[150001];
	bool ok[150001];
	cin>>n>>k>>q;

	for(int i=0; i<n; i++){
		cin>>t[i];
		ok[i]=false;
	}

	priority_queue < pair <int, int> > pq;
	for(int i=0; i<q; i++){
		int ctl, id;
		cin>>ctl>>id;
		id-=1;

		if(ctl==1){
			if (pq.size()<k){
				pq.push(make_pair(-t[id], id));
				ok[id] = true;
			}
			else{
				if(t[id]>t[pq.top().second]){
					ok[pq.top().second] = false;
					pq.pop();
					pq.push(make_pair(-t[id], id));
					ok[id] = true;
				}
			}
		}
		else{
			if(ok[id]){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
}
