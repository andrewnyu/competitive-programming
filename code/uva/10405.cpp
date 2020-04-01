#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
string temp1, temp2;

void clear(){
	for(int i=0; i<1001; i++){
		for(int j=0; j<1001; j++){
			dp[i][j] = -1; 
		}
	}
}

int lcs(int i, int j){
	if(i==0 || j==0){
		dp[i][j] = 0;
		return dp[i][j];
	}
	else if(dp[i][j]>=0){
		return dp[i][j];
	}
	else{
		if(temp1[i-1] == temp2[j-1]){
			dp[i][j] = lcs(i-1, j-1) + 1;  
		}
		else{
			if(lcs(i-1, j) > lcs(i, j-1)){
				dp[i][j] = lcs(i-1, j);
			}
			else{
				dp[i][j] = lcs(i, j-1);
			}
		}


		return dp[i][j]; 
	}
}

int main(){
	
	
	while(getline(cin,temp1)){ 
        getline(cin, temp2); 
		clear();
		cout<<lcs(temp1.length(), temp2.length())<<endl;


	}

	return 0; 
}