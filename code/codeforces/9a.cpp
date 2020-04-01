#include <iostream>
using namespace std;

int main(){
	int w,y;
	cin>>w>>y;

	int num = 6 - max(w,y) + 1;
	int dem = 6;
	
	if(num == 2){
		cout<<1<<"/"<<3<<endl;
	}
	else if(num == 4){
		cout<<2<<"/"<<3<<endl;
	}
	else if(num == 3){
		cout<<1<<"/"<<2<<endl;
	}
	else if(num == 6){
		cout<<1<<"/"<<1<<endl;
	}
	else{
		cout<<num<<"/"<<6<<endl;
	}


}