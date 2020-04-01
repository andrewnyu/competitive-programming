//cf1016b Segment Occurences
#include <iostream>
#include <numeric>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    string s,t;
    cin>>s;
    cin>>t;

    long long int cum_cnt[1001];
    cum_cnt[0] = 0;
    for(int i=0; i<n-m+1; i++){
        int valid = 1;
        for(int j=0; j<m; j++){
            if(t[j] != s[i+j]){
                valid = 0;
            }
        }
        cum_cnt[i+1] = cum_cnt[i] + valid;
    }

    int start = n-m+1;
    if(start<0){
        start = 0;
    }
    for(int i=start; i<n; i++){
            cum_cnt[i+1] = cum_cnt[i];
    }


    while(q--){
        int a,b;
        cin>>a>>b;
        b = b-m+1; 
        a = a-1;

        if(b>=a){
            cout<<cum_cnt[b]-cum_cnt[a]<<endl;
        }
        else{
            cout<<0<<endl;
        }

    }


}
