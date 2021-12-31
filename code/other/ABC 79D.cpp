//ABC 79D: Wall
#include <iostream>
using namespace std;

int main(){
	int h,w;
	long long int c[10][10];

	cin>>h>>w;

	for(int i=0; i<=9; i++){
		for(int j=0; j<=9; j++){
			cin>>c[i][j];
			
		}
	}

	int res[h*w+2];
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin>>res[i*w+j];
		}
	}

	//floyd warshall algorithm to get cheapest to 1
	for(int k=0; k<=9; k++){
		for(int i=0; i<=9; i++){
			for(int j=0; j<=9; j++){
				if(c[i][j] > c[i][k] + c[k][j]){
					c[i][j] = c[i][k] + c[k][j];
				}
			}
		}
	}

	long long int ans=0;
	for(int i=0; i<h*w; i++){
		if(res[i]!=-1){
			ans+=c[res[i]][1];
		}
	}

	cout<<ans<<endl;
}