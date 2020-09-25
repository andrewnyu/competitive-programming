//uva 10600: ACM Contest and Blackout
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXV = 100;
const int INTMX = 30001;
struct edge{
	int a,b,w;
};

bool compare(edge e1, edge e2){
	return e1.w<e2.w;
}

int p[MAXV+1];
int r[MAXV+1];
int find_set(int a){
	if(a==p[a]){
		return a;
	}
	else{
		p[a] = find_set(p[a]);
		return p[a];
	}
}

void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(r[a]<r[b]){
		p[b] = a;	
		r[a]+=r[b];
	}
	else{
		p[a] = b;
		r[b]+=r[a];
	}

}

void init(int n){
	for(int i=0; i<=n; i++){
		p[i]=i;
		r[i]=1;
	}
}



int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector <edge> arr;
		arr.clear();
		init(n);
		for(int i=0; i<m; i++){
			int a,b,w;
			cin>>a>>b>>w;
			arr.push_back((edge){a,b,w});
		}

		vector <int> tn;
		tn.clear();

		int s1=0;
		sort(arr.begin(),arr.end(),compare);
		for(int i=0; i<arr.size(); i++){
			if(find_set(arr[i].a)!=find_set(arr[i].b)){
				union_set(arr[i].a,arr[i].b);
				s1+=arr[i].w;
				tn.push_back(i);
			}
		}

		int s2 = INTMX;
		for(int i=0; i<tn.size(); i++){
			//cout<<i<<endl;
			init(n);
			int ts2 = 0;
			int cnt=0;
			for(int j=0; j<arr.size(); j++){
				if(j!=tn[i] &&(find_set(arr[j].a)!=find_set(arr[j].b))){
					union_set(arr[j].a,arr[j].b);
					ts2+=arr[j].w;
					cnt++;
				}
			}
			//cout<<tn[i]<<" "<<cnt<<" "<<ts2<<endl;
			if(cnt==n-1){
				s2=min(s2,ts2);
			}
		}

		cout<<s1<<" "<<s2<<endl;


		



	}
	
}