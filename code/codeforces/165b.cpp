#include <iostream>
using namespace std;

long long int n,k;
long long int compute(long long int a){
    long long int ans = a;
    long long int div = k;
    while(a>=div){
        ans += a/div;
        div*=k;
    }
    return ans;
}

long long int binary_search(long long int l, long long int r){
    long long int mid = (l+r)/2;
    if(compute(mid)>=n && compute(mid-1)<n){
        return mid;
    }
    else if(compute(mid-1)>=n){
        return binary_search(l, mid-1);
    }
    else{
        return binary_search (mid+1, r);
    }
    
}

int main(){
    cin>>n>>k;
    cout<<binary_search(0, n*k)<<endl;
}