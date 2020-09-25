//SPOJ CLOPPAIR: Closest Point Pair
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const double int_mx = 10000001;

struct pt{
	double x,y;
	int i;
};

class bt_compare{
public:
	bool operator() (pt p1, pt p2){
		return p1.y<p2.y;
	}
};

bool compare(pt p1, pt p2){
	return p1.x<p2.x;
}

int main(){
	int n;
	cin>>n;

	vector <pt> a;
	for(int i=0; i<n; i++){
		double x,y;
		cin>>x>>y;
		a.push_back((pt){x,y,i});
	}

	double res = int_mx;
	double rl, rr;
	set <pt, bt_compare> bt;
	sort(a.begin(), a.end(), compare);
	int left=0;
	for(int i=0; i<n; i++){
		while(a[i].x-a[left].x>=res){
			bt.erase(a[left]);
			left+=1;
		}

		set <pt>::iterator lb = bt.lower_bound((pt){a[i].x-res, a[i].y-res, i});
		for(set <pt>::iterator it=lb; it!=bt.end(); it++){
			double cdist = sqrt((it->x-a[i].x)*(it->x-a[i].x) + (it->y-a[i].y)*(it->y-a[i].y));
			if(cdist<res){
				res=cdist;
				rl = a[i].i;
				rr = it->i;
			}
		}

		bt.insert(a[i]);
	}

	cout<<min(rl,rr)<<" "<<max(rl,rr)<<" "<<fixed<<setprecision(6)<<res<<endl;
}