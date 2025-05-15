#include <bits/stdc++.h>
using namespace std;

int countDays(int days, vector<vector<int>>& meetings) {
    vector<bool> a(days+1,false);

    for(int i=0; i<meetings.size(); i++){
        for(int j=meetings[i][0]; j<=meetings[i][1]; j++){
            a[j]=true;
        }
    }
    
    int count=0;
    for(int i=1; i<=days; i++){
        if(a[i]==false) count++;
    }

    return count;
}

int main(){
    // my own solution worked just fine, but Time Limit Exceeded
}