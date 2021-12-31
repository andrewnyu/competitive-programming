//cf1205C: Shortest Cycle
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 100000;
const long long int MAXN = 1000000000000000000;
 
struct node{
	vector <int> nodes;
};
 
struct graph{
	node *edges[MAXV];
};
 
void add_edge(graph *g, int a, int b, bool directed){
	g->edges[a]->nodes.push_back(b);
	if(!directed){
		add_edge(g,b,a,true);
	}
}
 
bool visited[MAXV+1];
int parent[MAXV+1];
int d[MAXV+1];
int res;
void init(int n){
	for(int k=0; k<n; k++){
		d[k]=0;
		visited[k]=false;
	}
}
 
int v,w;
queue <int> q;
void bfs(graph *g){
	d[v] = 0;
	q.push(v);
	visited[v]=true;
	while(!q.empty()){
		int y = q.front();
		q.pop();
		for(int i=0; i<g->edges[y]->nodes.size(); i++){
			if(y==v && g->edges[y]->nodes[i]==w){
 
			}
			else if(g->edges[y]->nodes[i]==w){
				res=min(res,d[y]+1);
				while(!q.empty()){
					q.pop();
				}
			}
			else if(!visited[g->edges[y]->nodes[i]]){
				//cout<<g->edges[y]->nodes[i]<<" "<<d[y]<<endl; 
				d[g->edges[y]->nodes[i]] = d[y]+1;
				q.push(g->edges[y]->nodes[i]);
				visited[g->edges[y]->nodes[i]]=true;			
			}
		}
	}
}
 
int main(){
	int n;
	cin>>n;
	long long int a[n+1];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
 
	//check if any bit has more than 3 numbers
	long long int curr;
	bool sans = false;
	for(int b=0; b<60; b++){
		int cset = 0;
		curr = 1LL<<b;
		for(int i=0; i<n; i++){
			if(curr&a[i]){
				cset++;
			}
		}
		if(cset>=3){
			sans = true;
			break;
		}
	}
 	
 	//start of solution
	if(sans){
		cout<<3<<endl;
	}
	

	else{
		//no short answer available
		graph *g = new graph;
		for(int i=0; i<n; i++){
			g->edges[i] = new node;
		}
	 
		res=n+1;
		vector <pair<int,int> > arr;
		curr = 0;
		for(int b=0; b<60; b++){
			int fst=-1,lst=-1;
			curr = 1LL<<b;
			for(int i=0; i<n; i++){
				if(curr&a[i] && fst==-1){
					fst=i;
				}
				else if(curr&a[i]){
					lst=i;
				}
			}
			if(fst!=-1 && lst!=-1){
				add_edge(g,fst,lst,false);
				arr.push_back(make_pair(fst,lst));
				//cout<<fst<<" "<<lst<<endl;
			}
		}
	 
		for(int i=0; i<arr.size(); i++){
			init(n);
			v=arr[i].first,w=arr[i].second;
			bfs(g);
			//cout<<v<<" "<<w<<endl;
			//cout<<res<<endl;
		}
	 
		if(res==n+1){
			cout<<-1<<endl;
		}
		else{
			cout<<res+1<<endl;
		}
	}
	
}