#include <bits/stdc++.h>
using namespace std;


long long repairCars(vector<int>& ranks, int cars) {
    sort(ranks.begin(),ranks.end());
    long long count=0;
    for(int i=0; i<ranks.size(); i++){
        for(int j=1; j<cars; j++){
            
            count=max(static_cast<long long>(ranks[i]) * j * j, count); // still thinking
            
        }
    }
    return count;
}


int main(){

}