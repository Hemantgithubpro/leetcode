#include <bits/stdc++.h>
using namespace std;
// there is also a leetcode easy problem: isSubsequence
string result = ""; // should not use variable globally

bool isSubsequence(string &s, string &sub, int k)
{
    int i = 0, j = 0;
    int L = sub.length();
    int n = s.length();

    while (i < n && j < k + L)
    {
        if (s[i] == sub[j % L])
            j++;
        i++;
    }

    return j == k * L;
}

void backtracking(string &s, string &curr, vector<bool> &canUse, vector<int> &requiredFreq, int k, int maxLen)
{
    if (curr.length() > maxLen)
        return;

    if ((curr.length() > result.length()) || (curr.length() == result.length() && curr > result) && isSubsequence(s, curr, k))
        result = curr;

    for (int i = 0; i < 26; i++)
    {
        if (canUse[i] == false || requiredFreq[i] == 0)
            continue;

        // in backtracking
        // Do
        char ch = i + 'a';
        curr.push_back(ch);
        requiredFreq[i]--;

        // Explore
        backtracking(s, curr, canUse, requiredFreq, k, maxLen);

        // Undo
        curr.pop_back();
        requiredFreq[i]++;
    }
}

string longestSubsequenceRepeated(string s, int k)
{
    int n = s.length();

    int freq[26] = {};
    for (char &ch : s)
    {
        freq[ch - 'a']++;
    }

    vector<bool> canUse(26, false);
    vector<int> requiredFreq(26, 0);
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] >= k)
        {
            canUse[i] = true;
            requiredFreq[i] = freq[i] / k; // atmost
        }
    }

    int maxLen = n / k;

    // string curr;
    // backtracking(s, curr, canUse, requiredFreq, k, maxLen);

    

    return result;
}

int main()
{
    string s = "letsleetcode";
    int k = 2;

    cout << longestSubsequenceRepeated(s, k);
    return 0;
}