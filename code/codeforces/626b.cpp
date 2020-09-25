//626B: Cards
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 200;
bool visited[MAXV+1][MAXV+1][MAXV+1] = {false};
void dfs(int i, int j, int k){
	if(!visited[i][j][k]){
		visited[i][j][k] = true;
		if(i>1){
			dfs(i-1, j, k);
		}
		if(j>1){
			dfs(i,j-1,k);
		}
		if(k>1){
			dfs(i,j,k-1);
		}
		if(i>0 && j>0){
			dfs(i-1,j-1,k+1);
		}
		if(i>0 && k>0){
			dfs(i-1,j+1,k-1);
		}
		if(j>0 && k>0){
			dfs(i+1, j-1, k-1);
		}
	}
}

int main(){
	int n;
	string s;
	cin>>n;
	cin>>s;
	int b=0,g=0,r=0;

	int cnt = 0;
	for(int i=0; i<n; i++){
		if(s[i]=='B'){
			b++;
		}
		else if(s[i]=='G'){
			g++;
		}
		else{
			r++;
		}
	}

	dfs(b,g,r);
	string res = "";
	if(visited[1][0][0]){
		res+="B";
	}
	if(visited[0][1][0]){
		res+="G";
	}
	if(visited[0][0][1]){
		res+="R";
	}

	cout<<res<<endl;



}