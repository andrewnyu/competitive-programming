//Used online solution as reference
#include <iostream>
#include <vector>
using namespace std;
string commands [6] = {"fill A","fill B","empty A","empty B","pour A B","pour B A"};

int a,b,t;
bool solved;
const int MAXV = 1001;
bool ok[MAXV][MAXV] = {false}; //check if b has gone from state i to j
void solve(int na, int nb, vector <int> ans){    
    if(nb==t && !solved){
        for(int i=0; i<ans.size(); i++){
            cout<<commands[ans[i]]<<endl;
        }
        cout<<"success"<<endl;
        solved = true;
    }

    if(!solved){
        //fill A
        if(na!=a && !ok[a][nb]){
            ok[a][nb] = true;
            ans.push_back(0);
            solve(a, nb, ans);
            ans.erase(ans.end()-1);
            solve(na, nb, ans);
        }
        //fill B
        if(nb!=b && !ok[na][b]){
            ok[na][b] = true;
            ans.push_back(1);
            solve(na, b, ans);
            ans.erase(ans.end()-1);
            solve(na, nb, ans);
        }
        //empty A
        if(na!=0 && !ok[0][nb]){
            ok[0][nb] = true;
            ans.push_back(2);
            solve(0, nb, ans);
            ans.erase(ans.end()-1);
            solve(na, nb, ans);
        }
        //empty B
        if(nb!=0 && !ok[na][0]){
            ok[nb][0] = true;
            ans.push_back(3);
            solve(na, 0, ans);
            ans.erase(ans.end()-1);
            solve(na, nb, ans);    
        }
        //pour A B
        int nb1, na1;
        if(nb + na > b){
            nb1 = b;
            na1 = nb + na - b;
        }
        else{
            nb1 = nb + na;
            na1 = 0;
        }
        if(!ok[na1][nb1]){
            ok[na1][nb1] = true;
            ans.push_back(4);
            solve(na1, nb1, ans);
            ans.erase(ans.end()-1);
            solve(na, nb, ans);
        }

        //pour B A
        if(nb + na > a){
            na1 = a;
            nb1 = nb + na - a;
        }
        else{
            na1 = nb + na;
            nb1 = 0;
        }
        if(!ok[na1][nb1]){
            ok[na1][nb1] = true;
            ans.push_back(5);
            solve(na1, nb1, ans);
            ans.erase(ans.end()-1);
            solve(na, nb, ans);
        }
    }

}

int main(){
    //freopen("output.txt", "w", stdout);
    while(cin>>a){
        cin>>b>>t;
        solved = false;
        for(int i=0; i<MAXV; i++){
            for(int j=0; j<MAXV; j++){
                ok[i][j] = false;
            }
        }
        vector <int> init;
        init.clear();
        init.push_back(0);
        solve(a, 0, init);

    }
}