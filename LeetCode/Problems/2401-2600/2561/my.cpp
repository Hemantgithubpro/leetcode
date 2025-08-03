#include <bits/stdc++.h>
using namespace std;

bool isHashOk(vector<int> &b1, vector<int> &b2)
{
    int n = b1.size();
    unordered_map<int, int> um1, um2;
    for (int i = 0; i < n; i++)
    {
        um1[b1[i]]++;
        um2[b2[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        int temp = b1[i];
        if (um1[temp] != um2[temp])
            return false;
    }
    return true;
}

long long solve(vector<int> &b1, vector<int> &b2)
{
    if (!isHashOk(b1, b2))
        return -1;
    else
        return 0;
    // sort(basket1.begin(), basket1.end());
}

long long minCost(vector<int> &basket1, vector<int> &basket2)
{
    return solve(basket1, basket2);
}

int main()
{
    vector<int> b1 = {4, 1, 2, 2};
    vector<int> b2 = {1, 4, 2, 2};
    cout << minCost(b1, b2);

    return 0;
}