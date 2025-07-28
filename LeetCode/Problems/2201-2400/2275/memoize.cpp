#include <bits/stdc++.h>
using namespace std;
// correct soln but gave tle


int sizeofmaxi(vector<int> &c, int idx, int andval, int size, unordered_map<string, int> &memo)
{
    if (idx == c.size())
        return (andval > 0) ? size : 0;
    
    // Create a unique key for the current state
    string key = to_string(idx) + "|" + to_string(andval) + "|" + to_string(size);
    
    // Check if this state has already been computed
    if (memo.find(key) != memo.end())
        return memo[key];
    
    // Take current element
    int take = sizeofmaxi(c, idx + 1, (size == 0 ? c[idx] : (andval & c[idx])), size + 1, memo);
    // Don't take current element
    int skip = sizeofmaxi(c, idx + 1, andval, size, memo);
    
    // Store result in memo table
    memo[key] = max(take, skip);
    return memo[key];
}

int largestCombination(vector<int> &c)
{
    unordered_map<string, int> memo;
    return sizeofmaxi(c, 0, 0, 0, memo);
}

int main()
{
    vector<int> candidates = {16, 17, 71, 62, 12, 24, 14};
    cout << largestCombination(candidates);
}