#include <bits/stdc++.h>
using namespace std;

vector<int> getSneakyNumbers(vector<int> &nums)
{
    vector<int> ans;
    unordered_set<int> us;
    for (int n : nums)
    {
        if (us.count(n))
            ans.push_back(n);
        else
            us.insert(n);
    }
    return ans;
}
