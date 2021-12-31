//ABC 161D - LunLun NUmber
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
using namespace std;


int cnt=0;
string bfs(int k){

    
    string single_nums[10];
    for(int i=0; i<9; i++){single_nums[i] = to_string(i+1);}
    
    /*
    //special case to return single numbers
    if(k<=9){
        return single_nums[k-1];
    }
    */

    //count is at least 9 add single nums to queue
    queue <string> q;
    for(int i=0; i<9; i++){
        q.push(single_nums[i]);
    }

    string knum = "1";
    while(!q.empty() && cnt<k){
        string current = q.front();
        q.pop();
        cnt +=1;
        knum = current;
        int cld = current[current.length()-1]-'0'; 

        //cout<<cld<<" "<<current<<endl;

 
        if(cld-1>=0){
            q.push(current+to_string(cld-1));
        }

        q.push(current+to_string(cld));
        
        if(cld+1<10){
            q.push(current+to_string(cld+1));
        }  
   } 

  return knum; 
}



int main(){
    int k;
    cin>>k;

    string res = bfs(k);
    cout<<res<<endl;
}
