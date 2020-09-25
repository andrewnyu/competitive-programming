#include <iostream>
#include <map>
#include <queue>
using namespace std;
const int MAXV = 4002;
const int INF = 1000000;
struct edge{
	int w,d,c;

};

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	while(cin>>n&&n!=0){
		string s1,s2;
		map <string, int> lang;
		vector <edge> g[MAXV];
		long long int path[MAXV][26] = {INF};

		for(int i=0; i<2*n+2; i++){
			g[i].clear();
			for(int j=0; j<26; j++){
				path[i][j] = INF;
			}
		}

		cin>>s1>>s2;
		lang[s1] = 0;
		lang[s2] = 1;
		int cnt = 2;
		for(int i=0; i<n; i++){
			string word;
			cin>>s1>>s2>>word;
			if(lang.find(s1)==lang.end()){
				lang[s1] = cnt;
				cnt++;
			}
			if(lang.find(s2)==lang.end()){
				lang[s2] = cnt;
				cnt++;
			}
			g[lang[s1]].push_back((edge){(int)word.length(),lang[s2],word[0]-'a'});
			g[lang[s2]].push_back((edge){(int)word.length(),lang[s1],word[0]-'a'});		
		}

		//find shortest path from 0 to 1 given constraints
		priority_queue<pair<long long int,int>>pq;
		pq.push(make_pair(0,0));
		for(int i=0; i<26; i++){
			path[0][i] = 0;
		}
		while(!pq.empty()){
			int v = pq.top().second;
			pq.pop();
			for(int i=0; i<g[v].size(); i++){
				bool enq = false;
				long long int w = g[v][i].w;
				int c = g[v][i].c;
				int d = g[v][i].d;
				for(int j=0; j<26; j++){
					if((path[d][c]>path[v][j] + w) && c!=j){
							path[d][c] = path[v][j] + w;
							enq = true;							
						}
					}
					if(enq){
						pq.push(make_pair(-path[d][c],d));
					}
				}

			}
		

		long long int ans = path[1][0];
		for(int i=1; i<26; i++){
			if(path[1][i]<ans){
				ans = path[1][i];
			}
		}
		if(ans==INF){
			cout<<"impossivel"<<endl;
		}
		else{
			cout<<ans<<endl;
		}


	}
}