//ABC 168D - ..(Double Dots)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//problem will always be true for a BFS-able graph
//the sign in the room will be its parent in the bfs from 1

const int MAXV = 1e5;
int parent[MAXV+1];
bool ok[MAXV+1];

struct graph{
	vector <int> *edges[MAXV+1];
};

void bfs(int v, graph *g){
	ok[v] = true;
	queue <int> q;
	q.push(v);

	while(!q.empty()){
		v = q.front();
		q.pop();
		for(int i=0; i<(*g->edges[v]).size(); i++){
			int current = (*g->edges[v])[i];
			if(!ok[current]){
				ok[current] = true;
				parent[current] = v;
				q.push(current);
			}
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	graph *g = new graph;

	for(int i=0; i<n; i++){
		g->edges[i] = new vector <int>;
		ok[i] = false;
		parent[i] = i;
	}

	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		a-=1; 
		b-=1;

		(*g->edges[a]).push_back(b);
		(*g->edges[b]).push_back(a);
	}

	bfs(0, g);

	bool pos = true;
	for(int i=0; i<n; i++){
		if(!ok[i]){
			pos=false;
		}
	}

	//print result
	if(pos){
		cout<<"Yes"<<endl;
		for(int i=1; i<n; i++){
			cout<<parent[i]+1<<endl;
		}
	}
	else{
		cout<<"No"<<endl;
	}
}