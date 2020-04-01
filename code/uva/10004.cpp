//UVA 10004
#include <iostream>
#include <algorithm>
using namespace std;

struct graph{
	int degree[201];
	int edges[201][201];
};

int discovered [201];
int parent[201];
int color [201];  

void init_graph(graph *g){
	for(int i=0; i<201; i++){
		g->degree[i] = 0;
		discovered[i] = 0; 
		parent [i] = 0;
		color [i] = 0;
 	}
}

bool possible;
void dfs (graph *g, int v){
	if(!possible) return; 
	discovered[v] = true; 
	int y;

	for(int i=0; i<g->degree[v]; i++){
		y = g->edges[v][i]; 

		if(discovered[y] == false){
			parent[y] = v;
			color [y] = color[v] * -1; 
			dfs(g, y); 
		}
		else{
			if(color[y] == color[v]){
				possible = false; 
			}
		}
	}
}

int main(){
	int n,l;

	graph *g;
	g = (graph*) malloc(sizeof(graph)); 

	while(cin>>n){
		if(n==0){
			break;
		}

		else{
			cin>>l;
			int a,b;
			init_graph(g);


			while(l--){
				cin>>a>>b;
				g->edges[a][g->degree[a]] = b;
				g->edges[b][g->degree[b]] = a;
				g->degree[a]++;
				g->degree[b]++; 
			}

			possible = true;
			color[0] = 1;
			dfs (g, 0); 
			if(possible){
				cout<<"BICOLORABLE."<<endl;
			}
			else{
				cout<<"NOT BICOLORABLE."<<endl;
			}
		}
	}
	
}