#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int> &gain)
{
    int prev = 0;
    int next = 0;
    int ans = 0;
    for (int i = 0; i < gain.size(); i++)
    {
        next = prev + gain[i];
        prev = next;
        ans = max(ans, prev);
    }
    return ans;
}

int main()
{
}