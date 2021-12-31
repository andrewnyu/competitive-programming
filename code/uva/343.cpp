//UVA 343: What Base is This?
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	string s1,s2;
	while(cin>>s1){
		cin>>s2;

		vector <int> a1;
		vector <int> a2;
		a1.clear();
		a2.clear();

		for(int i=0; i<s1.size(); i++){
			if(s1[i]-'0'>9){
				a1.push_back((s1[i]-'A')+10);
			}
			else{
				a1.push_back(s1[i]-'0');
			}
		}

		for(int i=0; i<s2.size(); i++){
			if(s2[i]-'0'>9){
				a2.push_back((s2[i]-'A')+10);
			}
			else{
				a2.push_back(s2[i]-'0');
			}
		}

		//min base for each number
		int mb1=2;
		int mb2=2;
		for(int i=0; i<a1.size(); i++){
			mb1=max(mb1,a1[i]+1);
		}
		for(int i=0; i<a2.size(); i++){
			mb2=max(mb2,a2[i]+1);
		}

		//brute force
		int r1=-1;
		int r2=-1;
		for(int i=mb1; i<=36; i++){
			for(int j=mb2; j<=36; j++){
				long long int v1=0;
				long long int v2=0;

				for(int k=0; k<a1.size(); k++){
					v1+=a1[a1.size()-1-k]*pow(i,k);
				}

				for(int k=0; k<a2.size(); k++){
					v2+=a2[a2.size()-1-k]*pow(j,k);
				}

				if(v1==v2){
					r1=i;
					r2=j;

					//NOT elegant way to break loop
					i=37;
					j=37;
				}
			}
		}

		if(r1!=-1){
			cout<<s1<<" (base "<<r1<<") = "<<s2<<" (base "<<r2<<")"<<endl;
		}
		else{
			cout<<s1<<" is not equal to "<<s2<<" in any base 2..36"<<endl;
		}

	}
}