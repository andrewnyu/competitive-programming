#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct student{
    int score;
    string name;
};
struct region{
    vector <student> students;
    bool possible;
};

bool compare (student a, student b){
    return a.score > b.score;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector <region*> arr(m);
    for(int i=0; i<m; i++){
        arr[i]=new region;
        arr[i]->possible=true;
    }

    for(int i=0; i<n; i++){
        student s;
        int r;
        cin>>s.name>>r>>s.score;
        arr[r-1]->students.push_back(s);
    }

    for(int i=0; i<m; i++){
        sort(arr[i]->students.begin(),arr[i]->students.end(),compare);
        if(arr[i]->students.size()>2 && arr[i]->students[1].score == arr[i]->students[2].score){
            arr[i]->possible=false;
        }
    }

    for(int i=0; i<m; i++){
        if(arr[i]->possible){
            cout<<arr[i]->students[0].name<<" "<<arr[i]->students[1].name;
        }
        else{
            cout<<"?";
        }
        cout<<endl;
    }
}