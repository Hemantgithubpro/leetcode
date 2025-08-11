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

vector<int> productQueries(int n, vector<vector<int>> &queries)
{
    const int mod = 1e9 + 7;
    vector<int> powers = p(n);
    vector<int> ans;
    int s = queries.size();
    for (int i = 0; i < s; i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];
        long long temp = 1;
        for (int j = start; j <= end; j++)
        {
            temp *= powers[j];
            temp %= mod;
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n = 919;
    vector<int> a = p(n);
    for (int n : a)
    {
        cout << n << " ";
    }
    return 0;
}