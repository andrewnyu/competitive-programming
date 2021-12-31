//ABC 181C - Collinearity
#include <iostream>
#include <vector>
using namespace std;
double INF = 1e4; //placeholder for infinite slope

struct pt{
	double x,y;
};

double slope(pt p1, pt p2){
	if(p1.x==p2.x){
		return INF;
	}
	else{
		return (p1.y-p2.y)/(p1.x-p2.x);
	}
}

bool collinear(pt p1, pt p2, pt p3){
	double sp1 = slope(p1, p2);
	double sp2 = slope(p2, p3);

	if(sp1==sp2){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int n;
	cin>>n;
	vector <pt> arr;

	for(int i=0; i<n; i++){
		double cx, cy;
		cin>>cx>>cy;
		arr.push_back((pt){cx,cy});
	}

	bool res = false;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				if(collinear(arr[i], arr[j], arr[k])){
					res = true;
					break;
				}
			}
		}
	}

	if(res){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}