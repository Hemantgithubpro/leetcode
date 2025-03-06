#include <bits/stdc++.h>
using namespace std;
// did it myself in first try.
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector<int> ans;
    unordered_set<int> us;
    unordered_set<int> us2;
    int a,b;
    for(int i=0; i<grid.size();i++){
        for(int j=0; j<grid[i].size(); j++){
            if(us.find(grid[i][j])==us.end()){
                us.insert(grid[i][j]);
            }
            else a=grid[i][j]; 
        }
    }
    
    int k=1;
    for(int i=0; i<grid.size();i++){
        for(int j=0; j<grid[i].size(); j++){
            us2.insert(k++);
        }
    }

    for(int i=0; i<grid.size();i++){
        for(int j=0; j<grid[i].size(); j++){
            us2.erase(grid[i][j]); 
        }
    }
    auto it=us2.begin();
    b=*it;

    ans.push_back(a);
    ans.push_back(b);
    return ans;

}

int main(){

}