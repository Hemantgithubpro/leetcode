#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> num={1, 2, 2, 3, 4, 4, 4, 5, 1, 2};
    unordered_map<int, int> frequencyMap;
    for (int i=0; i<num.size(); i++) {
        frequencyMap[num[i]]++;
    }
    for(auto it: frequencyMap){
        cout<<it.first<<": "<<it.second<<endl;
    }
}