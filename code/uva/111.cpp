//UVA 111: History Grading
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	while(cin>>n){
		int val[n+2];
		int f[n+1];
		int a[n+1];
		int curr;
		for(int i=0; i<n; i++){
			cin>>curr;
			val[i]=curr;
		}

		bool cont=true;
		while(cont){
			for(int i=0; i<n; i++){
				if(scanf("%d",&curr)!=1){
					cont=false;
					break;
				}
				else{
					a[curr-1] = val[i];
					f[i]=1;
				}
			}

			/*
			for(int i=0; i<n; i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
			*/
			if(!cont){
				break;
			}

			//get LCS
			int res=1;
			f[0]=1;
			for(int i=1; i<n; i++){
				for(int j=0; j<i; j++){
					if(a[i]>a[j]){
						f[i]=max(f[i],f[j]+1);
						res=max(res,f[i]);
					}
				}
			}

			//cout<<res<<' '<<n<<endl;
			cout<<res<<endl;
		}
		n=curr;
		//cout<<curr<<endl;
	}
}