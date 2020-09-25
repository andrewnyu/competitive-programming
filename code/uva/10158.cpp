//uva 10158: war
#include <iostream>
using namespace std;
const int MAXV = 20004;
int p[MAXV+1];
int rk[MAXV+1];
int n;
int fs(int n){
	if(p[n]==n){
		return n;
	}
	else{
		p[n] = fs(p[n]);
		return p[n];
	}
}

void union_set(int a, int b){
	int pa = fs(a);
	int pb = fs(b);
	if(rk[pa]<rk[pb]){
		rk[pb]+=rk[pa];
		p[pa] = fs(b);
	}
	else{
		rk[pa]+=rk[pb];
		p[pb] = fs(a);
	}
}

int e(int x){
	return x+n;
}


int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);

	cin>>n;
	for(int i=0; i<2*n; i++){
		p[i] = i;
		rk[i] = 1;
	}

	int c,x,y;
	while(cin>>c && c!=0){
		cin>>x>>y;
		if(c==1){
			if((fs(e(x))==fs(y)) || (fs(e(y))==fs(x))){
				cout<<-1<<endl;
			}
			else{
				union_set(x,y);
				union_set(e(x),e(y));
			}
		}
		else if(c==2){
			if(fs(x)==fs(y)){
				cout<<-1<<endl;
			}
			else{
				union_set(x, e(y));
				union_set(y, e(x));
			}
		}
		else if(c==3){
			if(fs(x)==fs(y)){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		else{
			if(fs(e(x))==fs(y) || fs(e(y))==fs(x)){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}

}