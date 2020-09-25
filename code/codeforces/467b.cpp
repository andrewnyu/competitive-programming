#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector <int> arr;
    for(int i=0; i<m+1; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    int cnt = 0;
    for(int i=0; i<m; i++){
            int current = arr[i] ^ arr[m];
            int p = 1;
            int d = 0;
            while(p<=current){
                if(current & p){
                    d+=1;
                }
                p = p << 1;
            }
            if(d<=k){
                cnt+=1;
            }
    }

    cout<<cnt<<endl;
}