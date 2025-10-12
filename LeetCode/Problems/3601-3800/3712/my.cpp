#include <bits/stdc++.h>
using namespace std;

int sumDivisibleByK(vector<int> &nums, int k)
{
    int ans = 0;
    unordered_map<int, int> freq;
    for (int n : nums)
        freq[n]++;

    // unordered_set<int> vis;
    for (int n : nums)
    {
        // if(vis.count(n)) continue;
        if (freq[n] % k == 0)
        {
            ans += n;
            // vis.insert(n);
        }
    }
    return ans;
}

int main()
{
}