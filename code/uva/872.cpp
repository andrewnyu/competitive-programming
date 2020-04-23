#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
using namespace std;
const int MAXV = 26;
bool visited[MAXV] = {false};
bool adj[MAXV][MAXV] = {false};
int indegree[MAXV] = {0};
bool included[MAXV];
map <char, int> val;
map <int, char> c; 
vector <int> arr;
bool possible;

void top_sort_print(int n){
    //use recursive backtracking and Kahn's algorithm to print all possible solutions
    for(int i=0; i<MAXV; i++){
        if(included[i]){
            if(indegree[i]==0 && !visited[i]){
                for(int j=0; j<MAXV; j++){
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
                for(int j=0; j<MAXV; j++){
                    if(adj[i][j]){
                        indegree[j]++;
                    }
                }
            }
        }
    }
    //only print if:
    //1.) the array includes all elements (valid ordering)
    //2.) the array is not part of a partial removal dayon nag terminate lang kay waay na may ma butang.
    if(arr.size()==n){
        for(int i=0; i<arr.size(); i++){
            if(i==arr.size()-1){
                cout<<c[arr[i]];
            }
            else{
                cout<<c[arr[i]]<<" ";
            }
        }
        cout<<endl;
        possible = true;
    }

}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int cnt=0;
        for(int i=0; i<MAXV; i++){
            included[i] = false;
            visited[i] = false;
            indegree[i]=0;
            for(int j=0; j<MAXV; j++){
                adj[i][j]=false;
            }   
        }

        string s;
        while(s.length()==0)
            getline(cin, s);
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' '){
                val[s[i]]=s[i]-'A';
                c[s[i]-'A'] = s[i];
                included[s[i]-'A']=true;
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

        possible = false;
        top_sort_print(cnt);
        if(!possible){
            cout<<"NO"<<endl;
        }
        if(t>0){
            cout<<endl;
        }
    }
}