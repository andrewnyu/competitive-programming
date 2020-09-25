#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int MAXV = 1000000;


int main(){
    bool prime[MAXV+1];
    for(int i=2; i<=MAXV; i++){
        prime[i] = true;
    }
    for(int i=2; i<sqrt(MAXV)+1; i++){
        if(prime[i]){
            int num = i*i;
            while(num<=MAXV){
                prime[num]=false;
                num += i;
            }
        }
    }

    int n=1;
    while(n!=0){
        cin>>n;
        if(n!=0){
            string ans = "";
            bool pos = false;
            for(int i=2; i<=n/2; i++){
                if(prime[i] && prime[n-i]){
                    ans = to_string(n) + " = " + to_string(i) + " + " + to_string((n-i));
                    pos = true;
                    break;
                }
            }

            if(pos){
                cout<<ans<<endl;
            }
            else{
                cout<<"Goldbach's conjecture is wrong."<<endl;
            }
        }
    }

}