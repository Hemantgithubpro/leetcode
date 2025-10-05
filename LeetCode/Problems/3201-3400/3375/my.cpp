#include <bits/stdc++.h>
using namespace std;

// it worked thats all
int minOperations(vector<int> &nums, int k)
{
    unordered_set<int> us;
    for (int n : nums)
        us.insert(n);
    int smallest = *min_element(nums.begin(), nums.end());
    if (smallest < k)
        return -1;

    if (us.find(k) != us.end())
        return us.size() - 1;
    else
        return us.size();
}

int main()
{
}