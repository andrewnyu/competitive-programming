#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <long long int> arr;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
    int cnt = 0;
    long long int sum=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>=sum){
            cnt++;
            sum+=arr[i];
        }
    }

    cout<<cnt<<endl;
}