#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
	int list[1001]; 
};


int main(){
	int n;
	int a;
	int b;


	cin>>n>>a>>b;

	edge *edge_list[1001]; 

	for(int i=0; i<1001; i++){
		edge_list[i] = (edge*) malloc(sizeof(edge));
	}



	//check if possible
	if(a>1 && b>1){
		cout<<"NO"<<endl;
	}

	else if(a==1 && b==1){

		if((n<4) && n>1){
			cout<<"NO"<<endl;
		}
		else{
		cout<<"YES"<<endl;
			for(int i=1; i<n; i++){
				edge_list[i]->list[i+1] = 1;
				edge_list[i+1]->list[i] = 1;
			}

			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(i==j){
						cout<<"0";
					}
					else if(edge_list[i]->list[j] == 1){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				cout<<endl; 
			}
		}

	}

	else if(a>1){
		cout<<"YES"<<endl;
		for(int i=2; i<=n-a+1; i++){
			edge_list[1]->list[i] = 1;
			edge_list[i]->list[1] = 1; 
		}

		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j){
					cout<<"0";
				}
				else if(edge_list[i]->list[j] == 1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			cout<<endl; 
		}
	}

	else{
		//a=1 and b>1
		cout<<"YES"<<endl;
		for(int i=2; i<=n-b+1; i++){
			edge_list[1]->list[i] = 1;
			edge_list[i]->list[1] = 1; 
		}

		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j){
					cout<<"0";
				}
				else if(edge_list[i]->list[j] == 1){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
			cout<<endl; 
		}
	}

}
	
