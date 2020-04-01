#include <iostream>
#include <cstring>
using namespace std;
const int MAXV = 20001;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        string s;
        cin>>n>>k;
        cin>>s;

        int cnt = 0;
        for(int i=0; i<(double)k/(double)2; i++){
            int cnt_char[27] = {0};
            int cnt_total = 0;
            
            for(int j=i; j<n; j=j+k){
                int p1 = j;
                int p2 = (int(j/k)+1)*k - 1 - (j%k);

                if(p1==p2){
                    cnt_char[s[p1]-'a']++;
                    cnt_total += 1;
                }
                else{
                    cnt_char[s[p1]-'a']++;
                    cnt_char[s[p2]-'a']++;
                    cnt_total += 2;
                }

            }
            int mx = 0;
            for(int j=0; j<27; j++){
                if(cnt_char[j]>=mx){
                    mx = cnt_char[j];
                }
            }

            cnt += (cnt_total-mx);
        }
        cout<<cnt<<endl;

        

    }

}
