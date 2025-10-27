#include <bits/stdc++.h>
using namespace std;


// tle
int count(string &s)
{
    if (s.size() <= 1)
        return 0;
    unordered_map<char, int> um;
    
    // Count frequency of each character
    for (char c : s)
    {
        um[c]++;
    }
    
    // Find max and min frequencies
    int maxFreq = 0, minFreq = INT_MAX;
    for (auto &p : um)
    {
        maxFreq = max(maxFreq, p.second);
        minFreq = min(minFreq, p.second);
    }
    
    return maxFreq - minFreq;
}

int beautySum(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j <= s.size(); j++)
        {
            string p = s.substr(i, j - i);
            ans += count(p);
            // cout << i << ' ' << j << " ans: " << ans << endl;
        }
    }
    return ans;
}

int main()
{
    string s = "aabcb";

    cout << beautySum(s);

    string a = "aa";
    cout << count(a);
}