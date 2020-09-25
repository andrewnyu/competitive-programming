#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <int> parent;
vector <int> size;
void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v){
    if(v==parent[v])
        return v;
    else
        parent[v] = find_set(parent[v]);
        return parent[v];
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(size[a]<size[b]){
            int temp;
            temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        size[a] += size[b];
    }
}



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<=n; i++){
            //all computers start as a solo set
            if(i<parent.size()){
                parent[i] = i;
                size[i]= 1;
            }
            else{
                parent.push_back(i);
                size.push_back(i);
            }
        }

        string blank;
        getline(cin, blank);

        string s;
        int cnt_yes = 0;
        int cnt_no = 0;
        while(getline(cin, s) && s.length()>0){
            char q = s[0];
            string s1 = s.substr(2, s.find(' ',2)-2);
            string s2 = s.substr(s.find(' ',2)+1, s.length()-s.find(' ',2));
            int c1 = stoi(s1);
            int c2 = stoi(s2);

            if(q=='c'){
                union_sets(c1, c2);
            }
            else{
                if(find_set(c1)==find_set(c2)){
                    cnt_yes++;
                }
                else{
                    cnt_no++;
                }
            }
        }

        cout<<cnt_yes<<","<<cnt_no<<endl;
        if(t>0){
            cout<<endl;
        }
    }

}