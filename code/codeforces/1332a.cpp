#include<iostream>
using namespace std;

int main(){
    int t;
    long long int a,b,c,d;
    long long int x,y,x1,y1,x2,y2;
    cin>>t;

    while(t--){
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        bool possible = true;
        if(x+b-a > x2 || x+b-a <x1){
            possible = false;
        }

        if(y+d-c > y2 || y+d-c <y1){
            possible = false;
        }

        if(x1==x2 && (a!=0 || b!=0) || y1==y2 && (c!=0 || d!=0)){
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