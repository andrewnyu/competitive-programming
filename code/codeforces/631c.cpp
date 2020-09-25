//CF 631C: Report
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct query{
	int r,t,idx;
};

int main(){
	int n,m;
	cin>>n>>m;

	vector <long long int> a;
	for(int i=0; i<n; i++){
		long long int curr;
		cin>>curr;
		a.push_back(curr);
	}

	vector <query> qs;
	for(int i=0; i<m; i++){
		query c;
		cin>>c.t>>c.r;
		c.r--;
		c.idx=i;
		qs.push_back(c);
	}


	//int lst = qs[m-1].r;
	int res[n+1]; //0-original, 1-asc, 2-desc
	stack <query> op;
	op.push(qs[m-1]);

	for(int i=m-2; i>=0; i--){
		if(qs[i].r>op.top().r){
			if(qs[i].t==op.top().t){
				op.pop();
			}
			op.push(qs[i]);
		}
	}

	query c = op.top();
	for(int i=c.r+1; i<n; i++){
		res[i]=a[i];
	}


	sort(a.begin(), a.begin()+c.r+1);	

	stack <int> right;
	queue <int> left;
	for(int i=0; i<c.r+1; i++){
		right.push(a[i]);
		left.push(a[i]);
		//cout<<a[i]<<" ";
	}
	//cout<<endl;

	bool flag = false;	
	if(c.t==2){
		flag=true;
	}

	while(!op.empty()){
		c = op.top();
		op.pop();
		
		int st=0;
		if(!op.empty()){
			st=op.top().r+1;
		}
		
		for(int i=c.r; i>=st; i--){
			//cout<<i<<endl;
			if(!flag){
				res[i]=right.top();
				right.pop();
			}
			else{
				//cout<<left.front()<<endl;
				res[i]=left.front();
				left.pop();
			}
		}
		flag = !flag;
	}

	for(int i=0; i<n; i++){
		cout<<res[i]<<" ";
	}
}