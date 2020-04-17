#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    bool cont[59];
    int cnt[59];
    for(int i=0; i<58; i++){
        cnt[i]=0;
        cont[i] = false;
    }

    string s;
    cin>>s;

    for(int i=0; i<s.length(); i++){
        cont[s[i]-'A'] = true;
    }

    int ans=s.length();
    int l=0;
    int r=0;
    
    cnt[s[0]-'A']=1;
    while(r<s.length() && l<s.length()){

        bool valid=true;
        for(int i=0; i<58; i++){
            if(cnt[i]<=0 && cont[i]){
                valid=false;
            }
        }

        if(valid){
            if(r-l+1<ans){
                ans=r-l+1;
            }
            cnt[(int)(s[l]-'A')]--;
            l++;
        }
        else{
            r++;
            cnt[s[r]-'A']++;
        }
    }

    cout<<ans<<endl;



}