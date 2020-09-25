//cf 1263D: Secret Passwords
#include <iostream>
using namespace std;

bool edge[27][27];
bool visited[27];
void dfs(int v){
	visited[v] = true;
	for(int i=0; i<27; i++){
		if(edge[v][i]&&!visited[i]){
			dfs(i);
		}
	}
}

int main(){
	int n;
	cin>>n;

	for(int i=0; i<27; i++){
		visited[i] = true;
		for(int j=0; j<27; j++){
			edge[i][j] = false;
			edge[j][i] = false;
		}
	}

	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		for(int j=0; j<s.length(); j++){
			visited[s[j]-'a'] = false;
			for(int k=j+1; k<s.length(); k++){
				edge[s[j]-'a'][s[k]-'a'] = true;
				edge[s[k]-'a'][s[j]-'a'] = true;
			}
		}

	}
	/*
	for(int i=0; i<27; i++){
		cout<<visited[i]<<" ";
	}
	*/
	

	int res=0;
	for(int i=0; i<27; i++){
		if(!visited[i]){
			res++;
			dfs(i);
		}
	}

	cout<<res<<endl;
}