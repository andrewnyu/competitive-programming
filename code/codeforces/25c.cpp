#include <iostream>
#include <vector>
using namespace std;
const int MAXV = 301;
long long int d[MAXV][MAXV];

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>d[i][j];
		}
	}

	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	long long int sum=0;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			sum += d[i][j];
		}
	}

	int q;
	cin>>q;
	vector <long long int> ans;
	for(int t=0; t<q; t++){
		int a,b,w;
		cin>>a>>b>>w;
		a--;
		b--;
		if(w<d[a][b]){
			sum -= (d[a][b]-w);
			d[a][b] = w;
			d[b][a] = w;

			//tanan na distances to a and b updated na
			for(int i=0; i<n; i++){
				if(d[i][a] > d[i][b] + d[b][a]){
					sum -= (d[i][a] - d[i][b] - d[b][a]);
					d[i][a] = d[i][b] + d[b][a];
					d[a][i] = d[i][a];
				}
				if(d[i][b] > d[i][a] + d[a][b]){
					sum -= (d[i][b] - d[i][a] - d[a][b]);
					d[i][b] = d[i][a] + d[a][b];
					d[b][i] = d[i][b];
				}
			}

			//halin as tanan na pairs (i,j) may mas better pa gd na path via a or b?
			for(int i=0; i<n-1; i++){
				for(int j=0; j<n; j++){
					if(d[i][j]>d[i][a] + d[a][j]){
						sum -= (d[i][j] - d[i][a] - d[a][j]);
						d[i][j] = d[i][a] + d[a][j];
						d[j][i] = d[i][j];
					}
					if(d[i][j]>d[i][b] + d[b][j]){
						sum -= (d[i][j] - d[i][b] - d[b][j]);
						d[i][j] = d[i][b] + d[b][j];
						d[j][i] = d[i][j];
					}
				}
			}

		}

		ans.push_back(sum);
	}

	for(int i=0; i<q; i++){
		cout<<ans[i]<<" ";
	}
}