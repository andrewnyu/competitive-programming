#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector <int> arr;
        cin>>n;

        vector <bool> visited(n+1, false);
        vector <int> pos(n+1, 0);

        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            arr.push_back(a);
            pos[a] = i;
        }

        bool possible = true;
        for(int i=1; i<n; i++){
            if(pos[i]<n-1){
                if(arr[pos[i]+1]>i+1){
                    possible = false;
                }
            }
        }

        if(possible){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        

    }
}