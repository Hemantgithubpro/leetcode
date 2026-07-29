#include <bits/stdc++.h>
using namespace std;

// precompute factorials
unsigned long long fact(int n)
{
    static vector<unsigned long long> f = []()
    {
        vector<unsigned long long> v(21, 1);
        for (int i = 1; i <= 20; i++)
            v[i] = v[i - 1] * i;
        return v;
    }();
    if (n > 20)
        return ULLONG_MAX;
    return f[n];
}

string kthpermutation(string a, int k)
{
    int n = a.size();
    sort(a.begin(), a.end());

    int freq[26] = {0};
    for (char c : a)
        freq[c - 'a']++;

    auto countPermutations = [&](int rem) -> unsigned long long
    {
        unsigned long long cnt = fact(rem);

        for (int i = 0; i < 26; i++)
            cnt /= fact(freq[i]);

        return cnt;
    };

    string ans;

    for (int pos = 0; pos < n; pos++)
    {
        bool found = false;

        for (int ch = 0; ch < 26; ch++)
        {
            if (freq[ch] == 0)
                continue;

            // Try placing this character
            freq[ch]--;

            unsigned long long cnt = countPermutations(n - pos - 1);

            if (k > cnt)
            {
                // Skip all permutations beginning with this character
                k -= cnt;
                freq[ch]++;
            }
            else
            {
                // This is the correct character
                ans += char('a' + ch);
                found = true;
                break;
            }
        }

        if (!found)
            return "-1";
    }

    return ans;
}

string smallestPalindrome(string s, int k)
{
    int n = s.size();
    if (n % 2)
    {
        // leave the middle element
        string a = s.substr(0, n / 2);
        string b = kthpermutation(a, k);
        if (b == "-1")
            return "";
        string ans = b;
        ans += s[n / 2];
        reverse(b.begin(), b.end());
        ans += b;
        return ans;
    }
    else
    {
        string a = s.substr(0, n / 2);
        string b = kthpermutation(a, k);
        if (b == "-1")
            return "";
        string ans = b;
        reverse(b.begin(), b.end());
        ans += b;
        return ans;
    }
}

int main()
{
    string s = "abba";
    int k = 2;

    cout << smallestPalindrome(s, k);
    // cout<<kthpermutation("afa",2);
    return 0;
}