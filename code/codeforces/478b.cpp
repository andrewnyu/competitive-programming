#include <iostream>
using namespace std;

int main(){
    long long int n,m;
    cin>>m>>n;
    long long int mn, mx;

    mx = (m-n+1)*(m-n)/2;
    long long int d = m%n;
    mn = (n-d)*(m/n)*(m/n-1)/2 + d*(m/n+1)*(m/n)/2;

    cout<<mn<<" "<<mx<<endl;
    


}