//uva 10954: Add All
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(cin>>n && n!=0){
		priority_queue <int> pq;
		for(int i=0; i<n; i++){
			int a;
			cin>>a;
			pq.push(-a);
		}

		long long int res=0;
		while(!pq.empty()){

			long long int curr = -pq.top();
			pq.pop();
			curr+=-pq.top();
			pq.pop();
			//cout<<curr<<endl;
			if(!pq.empty()){
				pq.push(-curr);
			}
			
			res+=curr;
			
		}
		cout<<res<<endl;
	}
}