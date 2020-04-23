#include <iostream>
#include <queue>
using namespace std;
const int MAXV = 101;
int main(){
    int n,m;
    while(cin>>n){
        cin>>m;
        if(n==0 && m==0){
            break;
        }
        else{
            bool adj[MAXV+1][MAXV+1]={false};
            int indegree[MAXV+1]={0};
            for(int i=0; i<m; i++){
                int a,b;
                cin>>a>>b;
                adj[a-1][b-1]=true;
                indegree[b-1]++;
            }

            queue <int> q;
            for(int i=0; i<n; i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }

            vector <int> arr;
            while(!q.empty()){
                int y = q.front();
                q.pop();
                arr.push_back(y);

                for(int i=0; i<n; i++){
                    if(adj[y][i]){
                        indegree[i]--;
                        if(indegree[i]==0){
                            q.push(i);
                        }
                    }
                }
            }

            //problem has assurance of having no directed cycles
            for(int i=0; i<arr.size(); i++){
                cout<<arr[i]+1<<" ";
            }
            cout<<endl;


        }
    }
}