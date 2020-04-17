#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    string trash;
    getline(cin,trash);
    getline(cin,trash);

    while(t--){
        string a;
        long long int cnt = 0;
        map <string, long long int> sp;
        while(getline(cin,a) && a.length()>0){
            if(a.length()>0){
                sp[a]++;
                cnt++;
            }
        }

        map<string,long long int>::iterator it;
        for(it = sp.begin(); it!=sp.end(); it++){
            double ans = 100.0*(double)(it->second)/(double)cnt;
            cout<<it->first<<" "<<fixed<<setprecision(4)<<ans<<endl;
        }
        if(t>0){
            cout<<endl;
        }
    }
}