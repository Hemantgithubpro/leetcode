#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
    long long ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}
int possibleStringCount(string word, int k)
{
    const int MOD = 1e9 + 7;

    int ans = 1; // original string will always be there
    int n = word.size();
    int candelete = n - k;
    int start = 0;
    if (candelete <= 0)
        return 1;

    unordered_map<char, int> um;
    for (int i = 0; i < n; i++)
    {
        um[word[i]]++;
    }
    for (auto it = um.begin(); it != um.end(); it++)
    {
        it->second--;
        start++;
    }

    int rest = n - start;
    int temp = k - start;
    // PnC will be applied here.
    // restCtemp
    ans += nCr(rest, temp) % MOD;

    return ans;
}

int main()
{
    string word = "aabbccdd";
    int k = 7;
    cout << possibleStringCount(word, k);
    return 0;
}