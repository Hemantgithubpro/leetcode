#include <bits/stdc++.h>
using namespace std;

vector<int> shiftallzero(vector<int>& a){
    // int i=0;
    // int j=a.size()-1;
    // while(i<j){
    //     if(a[i]==0 && a[j]!=0) {
    //         swap(a[i],a[j]);
    //         i++;
    //         j--;
    //     }
    //     else if(a[j]==0){
    //         j--;
    //     }
    //     else if(a[i]!=0){
    //         i++;
    //     }
    // }
    // for(int i=0; i<a.size()-1; i++){
    //     if(a[i]==0 && a[i+1]!=0) swap(a[i],a[i+1]);
    // }
    vector<int> b;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=0) b.push_back(a[i]);
    }
    for(int j=b.size()-1; j<a.size(); j++){
        b.push_back(0);
    }
    return b;
}

vector<int> applyOperations(vector<int>& nums) {
    int n=nums.size()-1;
    for(int i=0; i<n-1; i++){
        if(nums[i]==nums[i+1]){
            nums[i]=nums[i]*2;
            nums[i+1]=0;
        }
    }
    return shiftallzero(nums);
}

int main(){
    // [1,2,4,4,5,5,2,1,1,0]
    // [1,2,8,0,10,0,2,2,0,0]
}