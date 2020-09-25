//CF 612D: The Union of K Segments
//Optimized algorithm - using in out instead of having additional loop
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<long long int,long long int>p1, pair<long long int,long long int>p2){
	if(p1.first==p2.first){
		return p1.second<p2.second;
	}
	else{
		return p1.first<p2.first;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n,k;
	cin>>n>>k;
	vector <pair<long long int,long long int>> arr;
	for(long long int i=0; i<n; i++){
		long long int a,b;
		cin>>a>>b;
		arr.push_back(make_pair(a,b));
	}

	sort(arr.begin(), arr.end(),compare);

	priority_queue <pair<long long int,long long int>> pq;
	vector <pair<long long int,long long int>> res;
	
	long long int cnt=1;
	long long int len_res = 0;
	int op=arr[0].first;
	pq.push(make_pair(-arr[0].second, arr[0].first));

	for(long long int i=1; i<n; i++){
		while(!pq.empty() && -pq.top().first<arr[i].first){
			if(cnt==k){
				len_res+=1;
				res.push_back(make_pair(op,-pq.top().first));			
			}
			cnt-=1;
			pq.pop();
		}

		pq.push(make_pair(-arr[i].second, arr[i].first));
		cnt+=1;
		if(cnt==k){
			op = arr[i].first;
		}

		else if(cnt>k){
			pq.pop();
			cnt-=1;
		}
	}

	if(cnt>=k){
		res.push_back(make_pair(op, -pq.top().first));
		len_res+=1;
	}

	cout<<len_res<<endl;
	for(long long int i=0; i<len_res; i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
}