#include <iostream>
#include <map>
#include <queue>
using namespace std;
const int MAXV = 51;
bool visited[MAXV] = {false};
bool adj[MAXV][MAXV] = {false};
int indegree[MAXV] = {0};
map <char, int> val;
map <int, char> c; 
vector <int> arr;

void top_sort_print(int n){
    //use recursive backtracking and Kahn's algorithm to print all possible solutions
    for(int i=0; i<n; i++){
        if(indegree[i]==0 && !visited[i]){
            for(int j=0; j<n; j++){
                if(adj[i][j]){
                    indegree[j]--;
                }
            }
            arr.push_back(i);
            visited[i] = true;
            top_sort_print(n);

            //backtrack
            visited[i]=false;
            //clear arr contents
            arr.erase(arr.end()-1);
            for(int j=0; j<n; j++){
                if(adj[i][j]){
                    indegree[j]++;
                }
            }
        }
    }
    //only print if:
    //1.) the array includes all elements (valid ordering)
    //2.) the array is not part of a partial removal dayon nag terminate lang kay waay na may ma butang.
    if(arr.size()==n){
        for(int i=0; i<arr.size(); i++){
            cout<<c[arr[i]]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        string blank;
        getline(cin, blank); //read blank line
        int cnt=0;

        string s;
        getline(cin, s);
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' '){
                val[s[i]]=cnt;
                c[cnt] = s[i];
                cnt++;
            }
        }
        getline(cin, s);
        for(int i=0; i<s.length(); i+=4){
            if(s[i+1]=='<'){
                adj[val[s[i]]][val[s[i+2]]] = true;
                indegree[val[s[i+2]]]++;              
            }
            else{
                adj[val[s[i+2]]][val[s[i]]] = true;
                indegree[val[s[i]]]++;               
            }
        }

        top_sort_print(cnt);

    }
}