#include <bits/stdc++.h>
using namespace std;

int funcus(vector<int> nums){
    unordered_set<int> us;
    for(int i=0; i<nums.size(); i++){
        us.insert(nums[i]);
    }
    return us.size();
}

void funcum(vector<int> nums){
    unordered_map<int,int> um;
    for(int i=0; i<nums.size(); i++){
        um[nums[i]]++;
    }
    for(auto it : um){
        cout << it.first << " : " << it.second << endl;
    }
    cout<<endl<<um.size();
    um[3]--;
    if(um[3]==0) um.erase(3);
    cout<<endl<<um.size();
}

int main(){
    // unordered_map<int,int> um;

    vector<int> nums={1,3,1,2,2};
    // cout<<funcus(nums);
    funcum(nums);
}