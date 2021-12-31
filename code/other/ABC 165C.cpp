//ABC 165C - Many Requirements
#include <iostream>
#include <vector>
using namespace std;

int n,m,q;

struct val{
  int a,b,c,d;  
};

val var[51];

long long int res = 0;
void dfs(vector <int> arr, int idx){
    long long int score = 0;
    
    /*
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    */

    if(idx==n-1){
        for(int i=0; i<q; i++){
            //already satisfies
            if(arr[var[i].b-1]-arr[var[i].a-1]==var[i].c){
                score+=var[i].d;
            }
        }

        if(score>res){
            res = score;
        }
    }
    else{
        for(int i=arr[idx]; i<=m; i++){
            arr[idx+1] = i;
            dfs(arr, idx+1);
        }
    }
}



int main(){
    
    cin>>n>>m>>q;    
    
    for(int i=0; i<q; i++){
       cin>>var[i].a>>var[i].b>>var[i].c>>var[i].d; 
    }

    vector <int> start;
    for(int i=0; i<n; i++){
        start.push_back(1);
    }

    for(int i=1; i<=m; i++){
        start[0] = i;
        dfs(start, 0);
    }

    cout<<res<<endl;
}


