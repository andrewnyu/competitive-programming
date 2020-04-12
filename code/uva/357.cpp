#include <iostream>
#include <cmath>
using namespace std;

long long int dp[30001][6]; //dp[n][m] sum n using m coins
int coins[6] = {1,5,10,25,50};
void init(){
    for(int i=0; i<30001; i++){
        for(int j=0; j<6; j++){
            dp[i][j] = -1;
        }
    }
}

long long int compute(int n, int m){
    if(n<0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    else if(m==0){
        dp[n][m] = 0;
        return dp[n][m];
    }
    else if(n==0){
        dp[n][m] = 1;
        return dp[n][m];
    }
    else{
        dp[n][m] = compute(n-coins[m-1],m) + compute(n, m-1);
        return dp[n][m];
    }
}

int main(){
    int n;
    init();
    while(cin>>n){
    	long long int ans = compute(n,5);
        if(ans==1){
        	cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
        }
        else{
        	cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change."<<endl;
        }
    }
}