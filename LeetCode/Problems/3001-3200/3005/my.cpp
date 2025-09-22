#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int n:nums){
            um[n]++;
        }
        int maxi=0,maxfrq=0;
        for(int n:nums){
            if(um[n]>maxfrq){
                maxi=n;
                maxfrq=um[n];
            }
        }
        int ans=0;
        for(int n:nums){
            if(um[n]==maxfrq) ans++; 
        }
        return ans;
    }
};

int main(){
    
}