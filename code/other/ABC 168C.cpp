//ABC 168C: :(Colon)
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI =  3.141592653589793;

double distance(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
	double a,b,h,m;
	cin>>a>>b>>h>>m;

	h*=(double)60;
	double mins = h+m;

	double ta = 2.0*PI*(int(mins)%720)/720.0;
	double tb = 2.0*PI*(int(mins)%60)/60.0;

	double opp1 = a*sin(ta);
	double adj1 = a*cos(ta);
	double opp2 = b*sin(tb);
	double adj2 = b*cos(tb);

	double dist = sqrt(pow((a*sin(ta)-b*sin(tb)),2) + pow((a*cos(ta)-b*cos(tb)),2));

	
	cout<<fixed<<setprecision(10)<<dist<<endl;
}