#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int t;
    int scenario = 1;
    map <int, int> team;
    while(cin>>t&&t!=0){
        for(int i=0; i<t; i++){
            int members;
            cin>>members;
            for(int j=0; j<members; j++){
                int a;
                cin>>a;
    	        team[a]=i;
            }
        }


        string s = "";
        vector <int> ans;
        vector <int> team_size (1001, 0);
        vector <queue<int>> team_members (1001);
        queue <int> q; //team queue
        while(cin>>s && s!="STOP"){
            if(s=="DEQUEUE"){
                ans.push_back(team_members[q.front()].front());
                team_members[q.front()].pop();
                team_size[q.front()]--;
                if(team_size[q.front()]==0){
                    q.pop();
                }
            }
            else{
                int a;
                cin>>a;
                if(team_size[team[a]]>0){
                    team_size[team[a]]++;
                    team_members[team[a]].push(a);
                }
                else{
                    team_size[team[a]]=1;
                    q.push(team[a]);
                    team_members[team[a]].push(a);
                }
            }
        }

        cout<<"Scenario #"<<scenario<<endl;
        scenario++;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<endl;
        }
        cout<<endl;
    }
}