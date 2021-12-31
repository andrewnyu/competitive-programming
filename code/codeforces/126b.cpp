//CF126B: Password
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int P = 31;
const long long int M = 1e9 + 7;


long long int fpow[1000001];
long long int mp(long long int a, long long int pow){
	if(fpow[pow]!=-1){
		return fpow[pow];
	}
	else if(pow==0){
		return 1;
	}
	else if(pow==1){
		return a;
	}
	else if(pow%2==0){
		return (mp(a, pow/2)*mp(a, pow/2))%M;
	}
	else{
		return (mp(a,pow/2)*mp(a,(pow/2)+1))%M;
	}
}

bool find_mid(string s, long long int h, int v){
	long long int ch=0;
	bool ok = false;
	for(int i=0; i<v; i++){
		ch = (ch + (s[s.length()-v-1+i]-'a'+1)*mp(P,i)%M)%M;
	}

	if(ch==h){
		ok=true;
	}

	//cout<<v<<" "<<ch<<" "<<h<<endl;
	for(int i=s.length()-v-2; i>=1; i--){
		ch = (M+((ch - ((s[i+v]-'a'+1)*mp(P,v-1))%M)*P)%M + (s[i]-'a'+1))%M;
		//cout<<v<<" "<<ch<<" "<<h<<endl;

		if(ch==h){
			ok=true;
		}
	}

	if(ok){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	string s;
	cin>>s;

	for(int i=0; i<s.length(); i++){
		fpow[i]=-1;
	}
	for(int i=0; i<s.length(); i++){
		fpow[i] = mp(P,i);
	}

	//rolling hash to indentify valid len
	vector < pair<int, int> >k;
	int n = s.length();
	long long int left=0;
	long long int right=0;
	for(int i=0; i<n-2; i++){        
		left = (left + ((s[i]-'a'+1)*mp(P,i))%M)%M;
		right = ((P*right)%M + (s[n-i-1]-'a'+1))%M;

		//cout<<i<<" "<<left<<" "<<right<<endl;
		
		if(left==right){
			k.push_back(make_pair(i+1,left));
		}
	}

	//binary search
	int l=0;
	int r=k.size()-1;
	int res=0;
	bool pos=false;

	//cout<<"here"<<endl;
	while(l<=r){
		if(l==r){
			if(find_mid(s,k[l].second,k[l].first)){
				pos=true;
				res=k[l].first;
			}
			l+=1;
		}
		else{
			int m = ((l+r)/2)+1;

			bool mf = find_mid(s, k[m].second, k[m].first);
			//cout<<l<<" "<<m<<" "<<r<<" "<<mf<<endl;

			if(mf){
				pos=true;
				l=m;
			}
			else{
				r=m-1;
			}
		}
	}
	//cout<<"here"<<endl;

	if(pos){
		for(int i=0; i<res; i++){
			cout<<s[i];
		}
		cout<<endl;
	}
	else{
		cout<<"Just a legend"<<endl;
	}



}