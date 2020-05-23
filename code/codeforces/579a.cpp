#include <iostream>
using namespace std;

int main(){
    int x;
    cin>>x;
    int a=1;
    int cnt=0;
    while(a<=x){
        if(x & a){
            cnt++;
        }
        a = a << 1;
    }
    cout<<cnt<<endl;
}