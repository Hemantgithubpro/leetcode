#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &b1, vector<int> &b2)
{
    int n = b1.size();
    unordered_map<int, int> um1, um2;
    for (int i = 0; i < n; i++)
    {
        um1[b1[i]]++;
        um2[b2[i]]++;
    }
    if (um1 == um2)
        return 0;
    sort(b1.begin(), b1.end());
    sort(b2.begin(), b2.end());

    long long ans = 0;
    for (int i = 0, j = 0; i < n - 1, j < n - 1;)
    {
        int ti = b1[i], tj = b2[j];
        if (ti == tj || b1[i + 1] == b2[j + 1])
        {
            i++;
            j++;
        }
        // else if (um1[ti]==)
            else if (b1[i] == b1[i + 1] && b2[i] == b2[i + 1])
            {
                ans += min(b1[i], b2[i]);
                i++;
            }
    }
    for (int i = 0; i < n; i++)
    {
        if (b1[i] == b2[i])
            continue;

        int temp1 = b1[i], temp2 = b2[i];
        int f1 = um1[temp1] - um2[temp1];
        int f2 = um2[temp2] - um1[temp2];
        if (f1 % 2)
            return -1;
        if (f2 % 2)
            return -1;
    }
    return ans;
}

long long minCost(vector<int> &basket1, vector<int> &basket2)
{
    return solve(basket1, basket2);
}

int main()
{
    vector<int> b1 = {4, 4, 4, 4, 3};
    vector<int> b2 = {5, 5, 5, 5, 3};
    cout << minCost(b1, b2);

    return 0;
}