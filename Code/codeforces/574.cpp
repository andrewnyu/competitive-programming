#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
bool possible = false; //whether or not a team of musketeers can be assembled
int min_friendship; 
int edge_list[4001][4001]; 
int degree[4001];

void init(){
	

	for(int i=0; i<4001; i++)for(int j=0; j<4001; j++){
		edge_list[i][j] = -1; 
		degree[i] = 0; 
	}
}

struct edge {
	int v1; 
	int v2;  
} ;






int main(){
	int n,m;
	cin>>n>>m; 
	edge edges [4001] ; 

	min_friendship = n*m; 
	init();

	for(int i=0; i<m; i++){
		int a,b;
		edge current; 
		cin>>a>>b;

		edges[i].v1 = a;
		edges[i].v2 = b; 
 
		degree[a]++;
		degree[b]++; 

		edge_list[a][b] = 1; 
		edge_list[b][a] = 1; 
		
	}

	for(int i=0; i<m; i++)for(int j=1; j<=n; j++){
		if(edge_list[edges[i].v1][j] == 1 && edge_list[edges[i].v2][j] ==1 ){
			possible = true;
			int tempscore = degree[edges[i].v1] + degree[edges[i].v2] + degree[j] - 6;

			if(tempscore < min_friendship){
				min_friendship = tempscore; 
			}
		}
	}








	if(possible){
		cout<<min_friendship<<endl;;
	}
	else{
		cout<<-1<<endl;
	}









}