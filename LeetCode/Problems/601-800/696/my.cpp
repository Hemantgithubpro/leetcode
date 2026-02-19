#include <bits/stdc++.h>
using namespace std;

// did on my own, after 1 rejection

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        vector<int> v;
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
        {
            int count = 1;
            while (s[i] == s[i + 1])
            {
                count++;
                char c = s[i];
                i++;
            }
            if (s[i] == '0')
                count *= -1;
            v.push_back(count);
        }
        if (n > 1 && s[n - 1] != s[n - 2])
        {
            if (s[n - 1])
                v.push_back(1);
            else
                v.push_back(-1);
        }
        int ans = 0;
        for (int i = 1; i < v.size(); i++)
        {
            // cout << v[i] << ' ';
            // int ab = abs(v[i]);
            // int a=abs(v[i])
            ans += min(abs(v[i]), abs(v[i - 1]));
        }
        cout << endl;
        return ans;
    }
};

int main()
{
    string s = "00110011000";
    Solution a;
    cout << a.countBinarySubstrings(s);
}