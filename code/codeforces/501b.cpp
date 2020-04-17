#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin>>n;
    map <string, string> current;
    map <string, string> changes;
    map <string, int> used;
    int cnt = 0;
    for(int i=0; i<n; i++){
        string s1,s2;
        cin>>s1>>s2;
        used[s1]++;
        used[s2]++;
        if(used[s1]==1){
            cnt++;
            changes[s1] = s2;
            current[s2] = s1;
        }
        else{
            changes[current[s1]] = s2;
            current[s2] = current[s1];
        }
    }
    cout<<cnt<<endl;
    map <string, string>::iterator it;
    for(it=changes.begin(); it!=changes.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}