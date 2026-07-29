#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string kthpermutation(string a, ll k)
{
    int n = a.size();
    sort(a.begin(), a.end());

    // Precompute factorials
    vector<ll> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;

    // Frequency array
    vector<int> freq(26, 0);
    for (char c : a)
        freq[c - 'a']++;

    auto countPermutations = [&](int remaining) -> ll
    {
        ll cnt = fact[remaining];

        for (int i = 0; i < 26; i++)
            cnt /= fact[freq[i]];

        return cnt;
    };

    string ans = "";

    for (int pos = 0; pos < n; pos++)
    {
        bool found = false;

        for (int ch = 0; ch < 26; ch++)
        {
            if (freq[ch] == 0)
                continue;

            // Try placing this character
            freq[ch]--;

            ll cnt = countPermutations(n - pos - 1);

            if (k > cnt)
            {
                // Skip all these permutations
                k -= cnt;
                freq[ch]++; // Restore
            }
            else
            {
                // This character belongs here
                ans += char(ch + 'a');
                found = true;
                break;
            }
        }

        if (!found)
            return "-1"; // k is larger than total permutations
    }

    return ans;
}