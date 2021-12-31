//UVA 10341: Solve It
//This is a really frustrating problem due to the precision issues. 
//Too precise and you can't solve, too imprecise and 4th decimal place is wrong
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double error = 1e-9;
double p,q,r,s,t,u;

double eval(double x){
	return (p*exp(-x)+q*sin(x)+r*cos(x) + s*tan(x) + t*x*x + u);
}


double fs(double l, double r){
	while(r-l>=error){
		double mid = (r+l)/2.0;
		if(eval(mid) < 0){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	return l;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	//from paper calculations function is stricly decreasing w.r.t x from 0<=x<=1
	while(cin>>p){
		cin>>q>>r>>s>>t>>u;

		double res = fs(0.0, 1.0);
		if(abs(eval(res))<=1e-4){
			cout<<fixed<<setprecision(4)<<res<<endl;
		}
		else{
			cout<<"No solution"<<endl;
		}
	}

}