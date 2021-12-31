//ABC84D - 2017-like Number

#include <iostream>
using namespace std;
const int MAXN = 1e5;

bool prime[MAXN+4];
void sieve(){
    int n = MAXN;
    prime[0] = prime[1] = false;
    for(int i=2; i<=n; i++){
        prime[i] = true;
    }

    //cout<<"here"<<endl;

    for(int i=2; i<=n; i++){
        if(prime[i]){
            long int k = i*i;
            while(k<=n){
                prime[k] = false;
                k+=i;
            }
        }

    }
}

int rsum[MAXN+4];

int main(){
    sieve();

    //cout<<"here"<<endl;

    int q;
    cin>>q;

    rsum[0] = rsum[1] = 0;
    for(int i=2; i<=MAXN; i++){
        if(i%2!=0){
            rsum[i] = rsum[i-1]+(prime[i] & prime[(i+1)/2]);
        }
        else{
            rsum[i] = rsum[i-1];
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        cout<<rsum[r] - rsum[l-1]<<endl;

    }
}