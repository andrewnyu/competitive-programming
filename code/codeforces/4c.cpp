#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    map <string, int> db;
    while(n--){
        string s;
        cin>>s;
        db[s]++;
        if(db[s]-1==0){
            cout<<"OK"<<endl;
        }
        else{
            cout<<s<<db[s]-1<<endl;
        }
    }
}