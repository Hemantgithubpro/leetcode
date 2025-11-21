#include <bits/stdc++.h>
using namespace std;

// need to fix this implemntation
int countPalindromicSubsequence(string s)
{
    unordered_set<char> us_left;
    unordered_map<char, int> um_right;
    int n = s.size();

    for (int i = 1; i < n; i++)
        um_right[s[i]]++;
    int count = 0;
    us_left.insert(s[0]);
    // palindromes of size 3
    // meaning either aaa or aba, only two types of subsequences are allowed
    for (int mid = 1; mid < n - 1; mid++)
    {
        char atmid = s[mid];
        um_right[atmid]--;
        for (char temp : us_left)
        {
            cout << temp << " ";
            if (um_right.count(temp)>0)
                count++;
        }
        us_left.insert(atmid);
        cout << endl;
    }

    return count;
}

int main()
{
    // string s = "aabca";
    string s = "bbcbaba";
    cout << countPalindromicSubsequence(s);
    return 0;
}