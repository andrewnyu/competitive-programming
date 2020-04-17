#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double a1,b1,a2,b2;
    double p1,p2,ans;
    cin>>a1>>b1>>a2>>b2;
    p1 = a1/b1;
    p2 = a2/b2;

    ans = p1*(1/(1-(1-p1)*(1-p2)));
    cout<<setprecision(10)<<ans<<endl;
}