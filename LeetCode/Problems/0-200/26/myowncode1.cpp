#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    set<int> a;
    for (int n : nums) {
        a.insert(n);
    }
    vector<int> ans;
    for (auto it = a.begin(); it != a.end(); it++) {
        ans.push_back(*it);
    }
    nums=ans;
    return a.size();
}

int main(){
    // this was the brute force solution, not the most optimal solution, next time I'll try two pointer approach, to do within just one for loop.
    vector<int> nums={2,5,2,7,1};
    cout<<removeDuplicates(nums); 
}