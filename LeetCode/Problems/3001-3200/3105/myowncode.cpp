// Its my own solution but its Time Complexity is O(n^3) which is not efficient
#include<bits/stdc++.h>
using namespace std;

    bool checkincre(const vector<int>& a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] >= a[i + 1])
            return false;
    }
    return true;
}

bool checkdecr(const vector<int>& a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] <= a[i + 1])
            return false;
    }
    return true;
}

vector<int> copyvec(const vector<int>& a, int start, int end) {
    vector<int> b;
    for (int i = start; i < end; i++) {
        b.push_back(a[i]);
    }
    return b;
}

int longestMonotonicSubarray(const vector<int>& nums) {
    if (nums.empty()) return 0; 

    int maxy = 1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
            vector<int> a = copyvec(nums, i, j + 1);
            if (checkincre(a) || checkdecr(a)) {
                maxy = max(maxy, j - i + 1);
            }
        }
    }
    return maxy;
}

int main(){
    vector<int> n={1,2,3,4,5,6,7,8,9,10};
    cout<<longestMonotonicSubarray(n);
    
}