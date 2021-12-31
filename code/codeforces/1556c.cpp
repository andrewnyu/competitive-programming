//CF 1556C: Compressed Bracket Sequence
//Contest upsolve with hints
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 1001;

int main(){

    int n;
    cin>>n;

    vector <long long int> arr;


    for(int i=0; i<n; i++){
        long long int a;
        cin>>a;

        arr.push_back(a);
    }


    long long int res=0;
    long long int minbalance = 0;
    long long int currbalance = 0;
    long long int balance = 0;
    for(int i=0; i<n-1; i++){
        currbalance = 0;
        minbalance=0;
        balance = 0;
        for(int j=i+1; j<n; j++){
            //number of subsequences strictly starting at i and ending at j
            if(i%2==0 && j%2==1){
                //pwede
                
                //if j-1==1 arr[i] will be subtracted even though it is openning brace
                if(i!=j-1){
                    balance+=arr[j-1];
                }

                long long int current = min(arr[i], arr[j]-balance) - max((long long int)0, -minbalance-1);
                res+=max(current,(long long int)0);

                //cout<<i<<" "<<j<<" "<<balance<<" "<<current<<endl;

                currbalance = max(currbalance,(long long int)0) - arr[j];
                if (i!=j-1){
                    currbalance+=arr[j-1];
                }

                minbalance += min(currbalance, (long long int)0);
                balance -= arr[j];

                
            }
        }
    }


    cout<<res<<endl;
}