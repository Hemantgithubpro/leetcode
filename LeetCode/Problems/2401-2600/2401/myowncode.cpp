// this is the POTD of 18 march 2025.
#include <bits/stdc++.h>
using namespace std;

// i've done this myself, and sample testcases are also correct. but memory limit exceeded.
vector<vector<int>> makeAllSubArrays(vector<int> b, int n){
    vector<vector<int>> v;
    for(int i=0; i<=b.size()-n; i++){
        vector<int> l;
        for(int j=i; j<n+i; j++){
            l.push_back(b[j]);
        }
        v.push_back(l);
    }
    return v;
}

bool isNice(vector<int> a){
    for(int i=0; i<a.size()-1; i++){
        for(int j=i+1; j<a.size(); j++){
            if((a[i]&a[j])>0) return false;
        }
    }
    return true;
}

int longestNiceSubarray(vector<int>& nums) {
    int ans=1;
    // one way is we can start from ans=nums.size(), and find if this size of subarray is nice exists or not, if not ans--, and continue
    int n=nums.size();
    while(n>1){
        vector<vector<int>> v=makeAllSubArrays(nums,n);
        for(int i=0; i<nums.size()-n+1; i++){
            if(isNice(v[i])) v[i].size()>ans ? ans=v[i].size() : ans=ans;
        }
        n--;
    }
    return ans;
}

int main(){
    
}