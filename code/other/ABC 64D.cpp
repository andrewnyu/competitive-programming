//ABC 64D: Insertion
#include <iostream>
#include <stack>
using namespace std;


int main(){
	int n;
	string s;
	stack <char> q;

	cin>>n;
	cin>>s;

	for(int i=0; i<n; i++){
		if(q.empty()){
			q.push(s[i]);
		}
		else if(q.top()=='(' && s[i]==')'){
			q.pop();
		}
		else{
			q.push(s[i]);
		}
	}

	while(!q.empty()){
		if(q.top()=='('){
			s=s+')';
		}
		else{
			s='('+s;
		}
		q.pop();
	}

	cout<<s<<endl;
}