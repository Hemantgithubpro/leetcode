#include <bits/stdc++.h>
using namespace std;

// time complexity is more, i dont know why
vector<string> divideString(string s, int k, char fill)
{
    int n = s.size();
    int noofgroups = n / k;

    vector<string> ans;
    for (int i = 0; i < n; i += k)
    {
        int temp = 0;
        string a = "";
        while (temp < k && (i + temp) < n)
        {
            a += s[i + temp];
            temp++;
        }
        ans.push_back(a);
    }

    if (n % k != 0)
    {
        noofgroups++;
        int b = ans[noofgroups - 1].size();
        int rest = k - b;
        while (rest--)
        {
            ans[noofgroups - 1] += fill;
        }
    }

    return ans;
}
