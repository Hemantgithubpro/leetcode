#include <bits/stdc++.h>
using namespace std;

// it is the brute force solution to the problem, optimal solution is to use a hash map to store the pairs of dominoes and their counts
bool isequal(vector<int> &a, vector<int> &b){
    if(a[0]==b[0] && a[1]==b[1]) return true;
    else if(a[0]==b[1] && a[1]==b[0]) return true;
    return false;
}
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ans=0;
    for(int i=0; i<dominoes.size()-1; i++){
        for(int j=i+1; j<dominoes.size(); j++){
            if(isequal(dominoes[i],dominoes[j])) ans++;
        }
    }
    return ans;
}

int main(){
    
}