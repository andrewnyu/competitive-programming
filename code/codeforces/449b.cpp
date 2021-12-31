//CF 449B: Jzzhu and Cities
#include <iostream>
#include <queue>
using namespace std;
const long long int MAXV = 1e5+1;
const long long int MX_INT = 1e15;

//algorithm -> regular djikstras with mark ontrain routes as tiebreaker
//given djikstras algorithm, as soon as a node is visited we are assured it is shortest path
//each time atrain route is added/replaced as a previous then subtract/add to max possible

struct route{
	long long int d,w;
};

struct node{
	vector <route> edges;
};

node *g[MAXV+1];

//baliktad comparator sng priority queue (below sorts descending)
class compare_route{
public:
	bool operator() (pair<long long int,long long int> &p1, pair<long long int,long long int> &p2){
		return p1.second>p2.second;
	}
};

long long int n,m,k;
long long int res=0;
long long int dist[MAXV+1]; //optimal distance
bool train[MAXV+1]; //using train to conneect capital
long long int tdist[MAXV+1]; //distance to capital via train
bool ok[MAXV+1]; //using train to conneect capital
void solve(){
	dist[1]=0;
	train[1]=false;
	ok[1]=true;

	priority_queue< pair<long long int,long long int>, vector < pair<long long int,long long int> >, compare_route> pq;
	for(long long int i=2; i<=n; i++){
		if(train[i]){
			dist[i] = tdist[i];
			pq.push(make_pair(i, dist[i]));
		}
		else{
			dist[i] = MX_INT;
		}
	}

	pq.push(make_pair(1,0));

	//solve
	while(!pq.empty()){
		long long int v = pq.top().first;
		long long int cdist = pq.top().second;
		//cout<<v<<" "<<pq.top().second<<endl;
		pq.pop();

		if(cdist<=dist[v]){
			for(long long int i=0; i<g[v]->edges.size(); i++){
				long long int w = g[v]->edges[i].w;
				long long int dest = g[v]->edges[i].d;

				if(dist[v]+w<dist[dest]){
					dist[dest]=dist[v]+w;
					if(train[dest]){
						res+=1;
						train[dest]=false;
					}
					pq.push(make_pair(dest,dist[dest]));
					ok[dest]=true;
				}
				else if((dist[v]+w==dist[dest]) && train[dest]){
					train[dest] = false;
					ok[dest]=true;
					res+=1;
				}
			}
		}
	}
}


int main(){
	cin>>n>>m>>k;

	//initialize all polong long inters
	for(long long int i=0; i<=n; i++){
		g[i] = new node;
		tdist[i]=MX_INT;
		train[i] = false;
		ok[i]=false;
	}

	for(long long int i=0; i<m; i++){
		long long int u,v,x;
		cin>>u>>v>>x;
		g[u]->edges.push_back((route){v,x});
		g[v]->edges.push_back((route){u,x});
	}

	int cnt = 0;
	for(long long int i=0; i<k; i++){
		long long int s,y;
		cin>>s>>y;
		tdist[s]=min(tdist[s],y);
		if(!train[s]){
			cnt+=1;
			train[s]=true;
		}
	}

	solve();

	cout<<(k-cnt)+res<<endl;
}