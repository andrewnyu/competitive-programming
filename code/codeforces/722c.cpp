#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <int> arr;
vector <int> parent;
vector <long long unsigned int> sum;
int find_set(int a){
    if(parent[a]==a){
        return a;
    }
    else{
        parent[a] = find_set(parent[a]);
        return parent[a];
    }
}

long long unsigned int mx;
void union_set(int a, int b){
    int new_head = find_set(a);
    sum[new_head] += sum[parent[b]];
    parent[b] = new_head;
    if(sum[new_head]>mx){
        mx = sum[new_head];
    }
}

int main(){
    int n;
    cin>>n;
    vector <bool> remaining (n+1, false);
    vector <int> remove (n);
    parent.resize(n);
    sum.resize(n);
    arr.resize(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cin>>remove[i];
    }

    for(int i=0; i<n; i++){
        sum[i] = arr[i];
        parent[i] = i;
    }

    mx = 1;
    vector <long long unsigned int> ans;
    for(int i=n-1; i>=0; i--){
        ans.push_back(mx);
        bool new_set = true;
        int new_index = remove[i]-1;
        remaining[new_index] = true;
        if(new_index>0 && remaining[new_index-1]){
            union_set(new_index-1, new_index);
            new_set = false;
        }
        if(new_index<n-1 && remaining[new_index+1]){
            union_set(new_index, new_index+1);
            new_set = false;
        }
        if(new_set){
            if(sum[new_index]>mx){
                mx = sum[new_index];
            }
        }
    }

    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<endl;
    }
    

    
}