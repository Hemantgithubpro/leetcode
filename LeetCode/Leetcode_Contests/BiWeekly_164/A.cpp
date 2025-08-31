#include <bits/stdc++.h>
using namespace std;

int getLeastFrequentDigit(int n)
{
    int noofdigits = 0;
    int t = n;
    unordered_map<int, int> um;
    while (t > 0)
    {
        noofdigits++;
        int a = t % 10;
        um[a]++;
        t /= 10;
    }
    int mini = 10;
    int ans = 10;
    for (auto it = um.begin(); it != um.end(); it++)
    {
        if (it->second < mini || (it->second == mini && it->first < ans))
        {
            mini = it->second;
            ans = it->first;
        }
    }
    return ans;
}

int main()
{
}