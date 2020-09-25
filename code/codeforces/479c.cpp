//CF 479C: Exams
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ex{
	int a, b;
};

bool compare(ex e1, ex e2){
	if(e1.a==e2.a){
		return e1.b<e2.b;
	}
	else{
		return e1.a<e2.a;
	}
}

int main(){
	int n;
	cin>>n;
	vector <ex> arr;
	for(int i=0; i<n; i++){
		int a,b;
		cin>>a>>b;
		arr.push_back((ex){a,b});
	}

	sort(arr.begin(),arr.end(),compare);

	int res=arr[0].b;
	for(int i=1; i<n; i++){
		if(arr[i].b>=res){
			res=arr[i].b;
		}
		else{
			res=arr[i].a;
		}
	}
	cout<<res<<endl;
}