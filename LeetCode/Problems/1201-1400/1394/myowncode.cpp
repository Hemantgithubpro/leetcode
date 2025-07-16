#include <bits/stdc++.h>
using namespace std;

int findLucky(vector<int> &arr)
{
    unordered_map<int, int> um;
    for (int i : arr)
        um[i]++;
    int maxi = -1;
    for (auto it = um.begin(); it != um.end(); it++)
    {
        if (it->first == it->second)
            maxi = max(maxi, it->first);
    }
    return maxi;
}

int main()
{
}