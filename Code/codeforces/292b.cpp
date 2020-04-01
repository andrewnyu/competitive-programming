#include <iostream>
using namespace std;

int main(){

int degree[100001];

int n,m;
cin>>n>>m;

for(int i=1; i<=n; i++){
	degree[i]=0;
}

for(int i=0; i<m; i++){
	int a,b;
	cin>>a>>b;

	degree[a]++;
	degree[b]++;
}

bool bus = true;
bool ring = true;
bool star = false;
int c_hub = 0;
int c_one = 0;

for(int i=1; i<=n; i++){

	if(degree[i] == n-1){
		star = true; 
	}

	if(degree[i]>2){
		ring = false; 
		bus = false; 
	}

	if(degree[i]>1){
		c_hub++;
	}

	if(degree[i]==1){
		c_one++; 
	}
}

//additional corrections
if(c_hub>1){
		star = false; 
	}
//end

if(ring && bus){
	if(c_one == 0){
		bus = false;
	}
	else if(c_one == 2){
		ring = false; 
	}
	else if(c_one > 2){
		ring = false;
		bus = false; 
	}
}



if(bus) {
	cout<<"bus topology"<<endl;
}

else if(ring){
	cout<<"ring topology"<<endl;
}

else if(star){
	cout<<"star topology"<<endl;
}

else{
	cout<<"unknown topology"<<endl;
}





	
}