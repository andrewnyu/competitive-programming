#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> arr;
    for(int i=0; i<n; i++){
        int a;
        scanf("%d",&a);
        arr.push_back(a);
    }


    int l=0;
    int r=0;
    int ans_l = 0;
    int ans_r = 0;
    int mx=0;
    int dpl = 0;
    map <int,int> cnt;

    cnt[arr[0]]=1;
    while(r<n-1){
        if(r-l+1-dpl>k){
            cnt[arr[l]]--;
            if(cnt[arr[l]]>=1){
                dpl--;
            }
            l++;
        }
        else{
            r++;
            cnt[arr[r]]++;
            if(cnt[arr[r]]>1){
                dpl++;
            }
            if(r-l+1>mx && r-l+1-dpl<=k){
                mx = r-l+1;
                ans_l = l;
                ans_r = r;
            }
        }
    }

   printf("%d %d\n",ans_l+1, ans_r+1);

}