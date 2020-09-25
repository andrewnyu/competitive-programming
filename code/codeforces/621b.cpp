#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
    int n;
    cin>>n;
    map <long long int, long long int> diff;
    map <long long int, long long int> sm;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        diff[a-b]++;
        sm[a+b]++;
    }

    long long int ans=0;
    map <long long int,long long int>::iterator it;
    for(it=diff.begin(); it!=diff.end(); it++){
        long long int num = it->second;
        ans += num*(num-1)/2;
    }
    for(it=sm.begin(); it!=sm.end(); it++){
        long long int num = it->second;
        ans += num*(num-1)/2;
    }
    cout<<ans<<endl;
}