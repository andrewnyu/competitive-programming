#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	int d[n+1][n+1];
	for(int i=0; i<n; i++){
		string a;
		cin>>a;
		for(int j=0; j<n; j++){
			if(a[j]=='0'){
				d[i][j] = 1001;
			}
			else{
				d[i][j] = 1;
			}
		}
	}

	int m;
	cin>>m;
	int arr[m+1];
	for(int i=0; i<m; i++){
		cin>>arr[i];
		arr[i]--;
	}

	//floyd warshall
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	vector <int> ans;
	ans.push_back(arr[0]);
	int b = 0;
	for(int i=2; i<m; i++){
		if(d[arr[b]][arr[i]]<i-b || arr[b]==arr[i]){
			ans.push_back(arr[i-1]);
			b = i-1;
		}
	}
	ans.push_back(arr[m-1]);

	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]+1<<" ";
	}
	cout<<endl;

}