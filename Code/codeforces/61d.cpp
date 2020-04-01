#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct edge{
	int d;
	int weight; 
};
struct edgelist{
	vector <edge> edj; 
};

struct graph{
	edgelist *edges[100001];
	int degree[100001];
};

bool visited[100001];
int min_route[100001]; //min route from i assuming no need to go back

void init(graph *g){
	for(int i=0; i<100001; i++){
		visited[i] = false;
		min_route[i] = -1; 
		g->degree[i] = 0; 
		g->edges[i] = NULL;
	}
}

int get_minpath(graph *g, int v){
	visited[v] = true;

	if(min_route[v]!=-1){
		return min_route[v]; 
	}

	else{
		int sum = 0;
		int max = 0;

		for(int i=0; i<g->edges[v]->edj.size(); i++){
			int y = g->edges[v]->edj[i].d; 

			if(visited[y] == false){
				int r = get_minpath(g, y) + g->edges[v]->edj[i].weight;
				sum += r;
				if(r > max){
					max = r; 
				}
			}
		}


		min_route[v] = max; 
		return min_route[v];
	}
}


int main(){
	int n;
	cin>>n;

	graph *g;
	g = new graph;
	init (g);


	for(int i=1; i<=n; i++){
		g->edges[i] = new edgelist;
	}

	long long int total = 0;
	for(int i=0; i<n-1; i++){
		int a,b,w;
		cin>>a>>b>>w;
		total += w;

		edge p;
		p.d = b;
		p.weight = w;
		g->edges[a]->edj.push_back(p);

		p.d = a;
		p.weight = w;
		g->edges[b]->edj.push_back(p);

	}

	cout<<2*total - get_minpath(g, 1)<<endl;




	

}