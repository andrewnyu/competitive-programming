#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    map <int, int> uq;
    vector<int> input;
    vector <int> arr (n+2,0);
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        input.push_back(a);
    }
    arr[n] = 0;
    for(int i=n-1; i>=0; i--){
        int a = input[i];
        uq[a]++;
        if(uq[a]==1){
            arr[i] = arr[i+1] + 1;
        }
        else{
            arr[i] = arr[i+1];
        }
    }

    for(int i=0; i<m; i++){
        int q;
        cin>>q;
        cout<<arr[q-1]<<endl;
    }

}