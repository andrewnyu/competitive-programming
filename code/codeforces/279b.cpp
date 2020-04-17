#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long int n,t;
    cin>>n>>t;
    vector <long int> arr;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    long int mx = 0;
    int start = 0;
    long int curr_sum = 0;
    long int curr_mx = 0;
    long int l = 0;
    long int r = 0;
        
    while(r<n){
        if(curr_sum+arr[r]<=t){
            curr_sum+=arr[r];
            curr_mx++;
            r++;

            if(curr_mx>mx){
                mx=curr_mx;
            }
        }
        else{
            curr_sum-=arr[l];
            l++;
            curr_mx--;
        }
    }

    cout<<mx<<endl;
}