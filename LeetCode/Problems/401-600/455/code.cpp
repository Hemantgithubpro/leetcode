#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(s.begin(), s.end());
    sort(g.begin(), g.end());
    int n = g.size();
    int m = s.size();
    int l = 0, r = 0;
    while (l < m)
    {
        if (s[l] >= g[r])
            r++;
        if (r == g.size())
            return r;
        l++;
    }
    return r;
}

int main()
{
}
