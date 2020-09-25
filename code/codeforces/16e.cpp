//CF 16E: Fish
#include <iostream>
#include <iomanip>
using namespace std;
double dp[1LL<<19];
double c[19][19];
int n;
double solve(long long int m){
    if(dp[m]!=-1){
        return dp[m];
    }
    else{
        dp[m]=0;
        double d = (double)__builtin_popcount(m);
        d = (double)1/((d+1)*d/2.0);
        //cout<<d<<endl;
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
        		if(!(m&(1LL<<i)) && (m&(1LL<<j))){
        		    //cout<<i<<" "<<j<<" "<<(m|(1LL<<i))<<endl;
        			dp[m]+=solve(m|(1LL<<i))*c[j][i]*d;
        		}
        	}
        }
        //cout<<dp[m]<<endl;
        return dp[m];
    }
}

int main(){

	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>c[i][j];
		}
	}
	
	for(int i=0; i<(1LL<<n); i++){
	    dp[i]=-1;
	}

	dp[(1LL<<n)-1]=1;
	//cout<<(1LL<<n) - 1<<endl;
    double res[n+1];
	for(int i=0; i<n; i++){
		res[i]=solve(1LL<<i);
	}

	for(int i=0; i<n; i++){
		cout<<fixed<<setprecision(7)<<res[i]<<" ";
	}


}