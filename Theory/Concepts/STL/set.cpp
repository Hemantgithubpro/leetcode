#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> a;
    vector<int> nums={2,5,2,7,1};
    for(int n: nums){
        a.insert(n);
    }
    for(auto it=a.begin(); it!=a.end(); it++){
        cout<<*it<<endl;
    }
  
}