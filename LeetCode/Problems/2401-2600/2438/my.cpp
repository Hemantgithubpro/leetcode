#include <bits/stdc++.h>
using namespace std;
vector<int> p(int n)
{
    // decimal to binary array
    vector<int> res;
    while (n > 0)
    {
        res.push_back(n % 2);
        n /= 2;
    }
    // reverse(res.begin(), res.end());
    vector<int> powers;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == 1)
            powers.push_back(pow(2, i));
    }
    return powers;
}

vector<int> prefixproduct(vector<int> &powers)
{
    const int mod = 1e9 + 7;
    int n = powers.size();
    vector<int> ans(n);
    ans[0] = powers[0];
    for (int i = 1; i < n; i++)
    {
        long long temp = ans[i - 1];
        temp *= powers[i];
        temp %= mod;
        ans[i] = (int)temp;
    }
    return ans;
}

vector<int> productQueries(int n, vector<vector<int>> &queries)
{
    vector<int> powers = p(n);
    vector<int> pref = prefixproduct(powers);
    vector<int> ans;
    int s = queries.size();
    for (int i = 0; i < s; i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];

        if (start == end)
        {
            ans.push_back(powers[start]);
            continue;
        }

        if (start > 0)
            start--;
        int t1 = pref[start];
        int t2 = pref[end];
        if (t1 != 0)
            ans.push_back(t2 / t1);
    }
    return ans;
}

int main()
{
    int n = 919;
    vector<int> a = p(n);
    // for (int n : a)
    // {
    //     cout << n << " ";
    // }

    // new syntax learned today of cpp
    vector ab(5, 1);
    cout << ab[3];
    return 0;
}