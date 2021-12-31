//UVA 1261: Password
#include <iostream>
using namespace std;

string res;
int cnt;
int k;
bool pos[7][27];

void solve(string s, int v){
	for(int i=0; i<26; i++){
		if(pos[v][i]){
			string cs = s+(char)('A'+i);
			//cout<<cs<<endl;
			if(v==4){
				cnt+=1;
				//cout<<cnt<<endl; 
				if(cnt==k){
					res=cs;
				}
			}
			else{
				solve(cs, v+1);
			}
		}
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>k;
		cnt=0;
		res="";

		int ok[7][27];
		for(int i=0; i<6; i++)for(int j=0; j<26; j++){
			ok[i][j]=false;
			pos[i][j]=false;
		}

		for(int i=0; i<12; i++){
			string col;
			cin>>col;

			if(i<6){
				for(int j=0; j<5; j++){
					pos[j][col[j]-'A']=true;
				}	
			}
			else{
				for(int j=0; j<5; j++){
					ok[j][col[j]-'A'] = true;
				}
			}

		}

		for(int i=0; i<6; i++)for(int j=0; j<26; j++){
			pos[i][j] = pos[i][j] && ok[i][j];
		}

		solve("",0);
		if(res==""){
			cout<<"NO"<<endl;
		}
		else{
			cout<<res<<endl;
		}
	}
}