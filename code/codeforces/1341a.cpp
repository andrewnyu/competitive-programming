#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        int x_min = a-b;
        int x_max = a+b;
        int tot_min = c-d;
        int tot_max = c+d;
        bool possible = true;
        if(x_max*n<tot_min){
            possible = false;
        }
        else if(x_min*n>tot_max){
            possible = false;
        }
        
        if(possible){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}