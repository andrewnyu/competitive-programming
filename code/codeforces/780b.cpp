#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
const double e = 1e-7;

int main(){
	int n;
	cin>>n;
	vector <double> x(n+1);
	vector <double> v(n+1);

	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	for(int i=0; i<n; i++){
		cin>>v[i];
	}

	//ternary search to obtain optimal value
	double l = 0;
	double r = 1e9;
	while(r-l>e){
		double m = (l+r)/2.0;
		double L=0,R=1e9;
		for(int i=0; i<n; i++){
			L=max(L,x[i]-m*v[i]);
			R=min(R,x[i]+m*v[i]);
		}
		
		if(R-L>e){
			r=m;
		}
		else{
			l=m;
		}
	}
	cout<<fixed<<setprecision(7)<<r<<endl;

}