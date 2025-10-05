#include <bits/stdc++.h>
using namespace std;

// this is the most optimal soln, and i wrote it myself.
bool isPossibleToSplit(vector<int> &nums)
{
    unordered_map<int, int> um;
    for (int n : nums)
    {
        um[n]++;
        if (um[n] > 2)
            return false;
    }
    int a = 0, b = 0;
    for (auto it = um.begin(); it != um.end(); it++)
    {
        if (it->second > 2)
            return false;
        if (it->second % 2 == 0)
        {
            a += it->second / 2;
            b += it->second / 2;
        }
        else
        {
            if (a >= b)
                b++;
            else
                a++;
        }
    }
    if (a == b && a + b == nums.size())
        return true;
    else
        return false;
}

int main()
{
}