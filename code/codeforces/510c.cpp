#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin>>n;
    bool adj[27][27]; //there is path from i to j
    int indegree[27];

    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            adj[i][j]=false;
        }
        indegree[i]=0;
    }

    vector<string> arr_s;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        arr_s.push_back(s);
    }

    bool possible = true;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            string s1 = arr_s[i];
            string s2 = arr_s[j];
            int k=0;
            while(s1[k]==s2[k]&&k<min(s1.length(),s2.length())-1){
                k++;
            }
            if(s1[k]!=s2[k]&&!adj[s1[k]-'a'][s2[k]-'a']){
                adj[s1[k]-'a'][s2[k]-'a']=true;
                indegree[s2[k]-'a']++;
            }
            else if(s1[k]==s2[k] && s1.length()>s2.length()){
                possible = false;
                //corner case: can't be fixed, complete word comes before prefix
            }
        }
    }

    vector<char> arr;
    queue <int> q;
    for(int i=0; i<26; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int x = q.front();
        char c = x+'a';
        arr.push_back(c);
        q.pop();

        for(int j=0; j<26; j++){
            if(adj[x][j] && x!=j){
                indegree[j]--;
                if(indegree[j]==0){
                    q.push(j);
                }
            }
        }
    }

    if(arr.size()<26 || !possible){
        cout<<"Impossible"<<endl;
    }
    else{
        for(int i=0; i<26; i++){
            cout<<arr[i];
        }
        cout<<endl;
    }

    

    

}