#include <bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N){
    // using brute force: hashing.
    map<int,int> mpp;
    for(int i=0; i<N; i++){
        mpp[Arr[i]]++;
    }
    vector<long long int> ans;
    for(auto it:mpp){
        if(it.second&1) ans.push_back(it.first);
    }
    sort(ans.begin(),ans.end(), greater<int>());
    return ans;
    
    
    // for(auto it : mpp){
    //     cout << it.first << " " << it.second << endl;
    // }

    // two bucket approach
    // couldn't understand it.

}

int main(){
    
}