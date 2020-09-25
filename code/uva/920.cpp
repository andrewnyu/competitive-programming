#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct coordinate{
    double x;
    double y;
    double b;
};

bool compare(coordinate a, coordinate b){
    return a.x < b.x;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector <coordinate> arr;

        for(int i=0; i<n; i++){
            coordinate a;
            cin>>a.x>>a.y;
            arr.push_back(a);
        }

        sort(arr.begin(), arr.end(), compare);
        arr[n-1].b = arr[n-1].y;
        for(int i=n-2; i>=0; i--){
            if(arr[i+1].y>arr[i+1].b){
                arr[i].b = arr[i+1].y;
            }
            else{
                arr[i].b = arr[i+1].b;
            }
        }


        double ans = 0;
        for(int i=0; i<n-1; i++){
            if(arr[i].y > arr[i].b){
                double slope = (arr[i].y - arr[i+1].y)/(arr[i].x - arr[i+1].x);
                double run = arr[i].y-arr[i].x*slope;
                double y1 = arr[i].b;
                double x1 = (arr[i].b-run)/slope;
                ans += sqrt((arr[i].x-x1)*(arr[i].x-x1) + (arr[i].y-y1)*(arr[i].y-y1));
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;
        
    }
}