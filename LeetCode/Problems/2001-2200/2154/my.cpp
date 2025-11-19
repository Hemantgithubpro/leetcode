#include <bits/stdc++.h>
using namespace std;

int findFinalValue(vector<int> &nums, int original)
{
    unordered_set<int> us;
    for(int n:nums) us.insert(n);

    while(us.count(original)){
        original*=2;
    } 
    return original;
}

int main()
{
}