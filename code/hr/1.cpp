#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Hackerrank: ice cream parlor

struct idx {
    int index;
    int value; 
};

bool compare (idx a, idx b){
    return a.value <= b.value;
}

int binary_search(vector<idx>arr, int val, int l, int r){
    if(r<l){
        return -1;
    }
    else{
        int mid = l + (r-l)/2;
        if(arr[mid].value==val){
            return mid;
        }
        else if(arr[mid].value<val){
            return binary_search(arr, val, mid+1, r);
        }
        else{
            return binary_search(arr, val, l, mid-1);
        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>m>>n;
        vector <idx> cost;

        for(int i=0; i<n; i++){
            idx a;
            cin>>a.value;
            a.index = i;
            cost.push_back(a);
        }
        sort(cost.begin(), cost.end(), compare);


        int a,b;
        for(int i=0; i<n; i++){
            int j = binary_search(cost, m-cost[i].value, 0, n-1);

            if(cost[i].index!=cost[j].index && j!=-1){
                a = cost[i].index + 1;
                b = cost[j].index + 1;
                break;
            }
        }

        if(a>b){
            int temp = a;
            a = b;
            b = temp;
        }

        cout<<a<<" "<<b<<endl;
    }
    
}