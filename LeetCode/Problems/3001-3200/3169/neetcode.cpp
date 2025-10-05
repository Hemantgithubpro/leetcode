#include <bits/stdc++.h>
using namespace std;


int countDays(int days, vector<vector<int>>& meetings) {
    // meetings may overlap.

    // sort meetings on the basis of first day
    sort(meetings.begin(),meetings.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0]<b[0];
    });

    int prev_day=0;
    for(int i=0; i<meetings.size(); i++){
        int start=max(meetings[i][0],prev_day+1);
        int length=meetings[i][1] - start +1;
        days-= max(length,0);
        prev_day=max(prev_day,meetings[i][1]);
    }
    return days;

}


int main(){
    int days=10;
    vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
    cout<<meetings[0][0];

}