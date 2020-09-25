#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string s1, string s2){
    return s1+s2<s2+s1;
}

int main(){
    int n;
    cin>>n;
    vector <string> arr;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }

    sort(arr.begin(),arr.end(),compare);
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
}