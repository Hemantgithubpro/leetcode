#include <bits/stdc++.h>
using namespace std;
// soln by tle eliminator
int numberOfSubstrings(string s)
{
    // max no. of 0 it can contain is sqrt(n), n: size of string
    // TC: n.sqrt(n)
    int n = s.size();

    int count = 0;
    vector<int> zeroidx;
    zeroidx.push_back(-1); // there may be case where there is no '0'

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zeroidx.push_back(i);

        int m = zeroidx.size();
        int num = 0;
        int idx = i;
        int previdx = -1;
        for (int j = m - 1; j >= 0; j--)
        {
            int val = num * num;
            if (val > i + 1)
                break;
            previdx = idx;
            idx = zeroidx[j];
            int numOne = i - idx - num;

            if (numOne >= val)
                count += min(numOne - val + 1, previdx - idx);
            num++;
        }
    }
    return count;
}

int main()
{
}