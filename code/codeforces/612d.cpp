//CF 612D: The Union of K Segments
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
	vector <pair<long long int,long long int>> sat;
	long long int cnt=0;
	long long int len_sat = 0;
	for(long long int i=0; i<n; i++){
		pq.push(make_pair(-arr[i].second, arr[i].first));
		cnt+=1;
		while(-pq.top().first<arr[i].first){
			cnt-=1;
			pq.pop();
		}
		if(cnt==k){
			len_sat+=1;
			sat.push_back(make_pair(arr[i].first,min(arr[i].second,-pq.top().first)));
			cnt-=1;
			pq.pop();
		}
	}

	vector <pair<long long int,long long int>> res;
	long long int len_res=0;
	long long int fst=0,lst=0;
	if(len_sat>0){
		len_res=1;
		fst=sat[0].first;
		lst=sat[0].second;
	}

	for(long long int i=1; i<len_sat; i++){
		if(sat[i].first<=lst){
			lst=max(lst,sat[i].second);
		}
		else{
			len_res+=1;
			res.push_back(make_pair(fst,lst));
			fst = sat[i].first;
			lst = sat[i].second;
		}
	}
	res.push_back(make_pair(fst,lst));

	cout<<len_res<<endl;
	for(long long int i=0; i<len_res; i++){
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}
}