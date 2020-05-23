#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> arr;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
    for(int i=0; i<n-1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[n-1];
}