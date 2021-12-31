//CF 431B: Shower Line
#include <iostream>
using namespace std;

int mx = -1;
int g[6][6];
string res = "";
void backtrack(string a){
	if(a.length()==5){
		int curr = g[a[0]-'0'][a[1]-'0'] + g[a[1]-'0'][a[0]-'0'] + g[a[1]-'0'][a[2]-'0'] + g[
			a[2]-'0'][a[1]-'0'] + 2*(g[a[2]-'0'][a[3]-'0'] + g[a[3]-'0'][a[2]-'0'] + g[a[3]-'0'][a[4]-'0'] + g[a[4]-'0'][a[3]-'0']);

		mx = max(curr, mx);
		if(curr==mx){
			res = a;
		}
	}
	else{
		bool ok[6];
		for(int i=0; i<5; i++){
			ok[i]=false;
		}

		for(int i=0; i<a.length(); i++){
			ok[a[i]-'0']=true;
		}

		for(int i=0; i<5; i++){
			if(!ok[i]){
				backtrack(a+(char)('0'+i));
			}
		}
	}
}

int main(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cin>>g[i][j];
		}
	}

	backtrack("");
	cout<<mx<<endl;
}