//UVA 12405: Scarecrow
#include <iostream>
using namespace std;

int main(){
	//freopen("input.txt", "r",stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin>>t;

	for(int test=1; test<=t; test++){
		int n;
		cin>>n;
		string s;
		cin>>s;

		int i=0;
		int cnt=0;
		while(i<n){
			if(s[i]=='.'){
				//put scarecrow to the right
				i=i+3;
				cnt+=1;
			}
			else{
				i+=1;
			}
		}

		cout<<"Case "<<test<<": "<<cnt<<endl;
	}
}