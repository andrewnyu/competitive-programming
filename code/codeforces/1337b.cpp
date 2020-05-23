#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,n,m;
        cin>>x>>n>>m;

        bool possible=false;
        while(x>=21 && n>0){
            x = x/2 + 10;
            n--;
        }

        if(x<=m*10){
            possible=true;
        }

        if(possible){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}