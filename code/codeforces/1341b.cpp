#include <iostream>
#include <vector>
using namespace std;

int main(){ 
    int t;
    cin>>t;
    while(t--){
        int n,k;
        vector <long long int> arr;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            long long int a;
            cin>>a;
            arr.push_back(a);
        }

        vector <long long int> left(n,0); //number of peaks in[0,p] inclusive
        long long int cnt = 0;
        for(int i=1; i<n-1; i++){
            if(arr[i-1]<arr[i] && arr[i+1]<arr[i]){
                left[i-1]=1;
                cnt++;
            }
        }
        for(int i=0; i<n-1; i++){
            left[i+1] += left[i];
        }

        int mx = left[k-3] + 1;
        int l = 1;
        for(int i=1; i<=n-k; i++){
            if(left[i+k-3]-left[i-1]+1>mx){
                mx = left[i+k-3] - left[i-1]+1;
                l = i+1;
            }
        }

        cout<<mx<<" "<<l<<endl;

    }
}