#include <bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n)
{
    vector<int> ans(n, 0);
    for (int i = 0; i < n - 1; i += 2)
    {
        ans[i] = i + 1;
        ans[i + 1] = -1 * ans[i];
    }
    return ans;
}