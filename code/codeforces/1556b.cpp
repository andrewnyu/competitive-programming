//CF 1556B: Take Your Places!
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int min_flips(int start, vector <int> arr){
    int exp = start; 
    int res = 0;

    priority_queue <int> pq0;
    priority_queue <int> pq1;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]==0){
            pq0.push(-i);
        }
        else{
            pq1.push(-i);
        }
    }


    for(int i=0; i<arr.size()-1; i++){
        if (arr[i]!=exp){

            //swap nearest correct element
            int next; //index of next correct element
            if(exp==0){
                next = abs(pq0.top());
                pq0.pop();

                while(next<=i){
                    next = abs(pq0.top());
                    pq0.pop();
                }

                pq1.push(-next);
            }
            else{
                next = abs(pq1.top());
                pq1.pop();

                while(next<=i){
                    next = abs(pq1.top());
                    pq1.pop();
                }

                pq0.push(-next);
            }

            res+=(next-i);
            int temp = arr[i];
            arr[i] = arr[next];
            arr[next] = temp;

        }
        exp = 1-exp; 
    }

    return res;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector <int> arr;
        arr.clear();

        int pcnt[2]; //parity count
        pcnt[0]=0; pcnt[1] = 0;

        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            arr.push_back(a%2);
            pcnt[a%2]+=1;
        }

        int res = 0;
        if(abs(pcnt[0]-pcnt[1])>1){
            res=-1;
        }
        else{
            if(pcnt[0]==pcnt[1]){
                res = min(min_flips(0, arr), min_flips(1, arr));
            }
            else{
                int start = (pcnt[1]>pcnt[0]);
                //cout<<start<<endl;
                res = min_flips(start, arr);
            }
        }

        //cout<<"Answer: "<<res<<endl;
        cout<<res<<endl;


    }
}