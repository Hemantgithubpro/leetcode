#include <bits/stdc++.h>
using namespace std;
// soln is correct but tle

int noofab(string &s)
{
    int noofab = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'b')
            noofab++;
    }
    return noofab;
}
int noofba(string &s)
{
    int noofba = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'b' && s[i + 1] == 'a')
            noofba++;
    }
    return noofba;
}
string reduceab(string s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'b')
        {
            s[i] = '.';
            s[i + 1] = '.';
        }
    }
    string sn = "";
    int it = 0;
    while (it < s.size())
    {
        if (s[it] != '.')
            sn += s[it];
        it++;
    }
    return sn;
}
string reduceba(string s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'b' && s[i + 1] == 'a')
        {
            s[i] = '.';
            s[i + 1] = '.';
        }
    }
    string sn = "";
    int it = 0;
    while (it < s.size())
    {
        if (s[it] != '.')
            sn += s[it];
        it++;
    }
    return sn;
}

int maximumGain(string s, int x, int y)
{
    // ig dp
    // but lets try counting ab and ba
    int nab = noofab(s), nba = noofba(s);
    int maxi = 0;
    // whatever is larger x or y, remove according to that
    if (x >= y)
    {
        while (noofab(s) > 0)
        {
            nab = noofab(s);
            maxi += (nab * x);
            s = reduceab(s);
        }

        // now check ba in sn
        while (noofba(s) > 0)
        {
            nba = noofba(s);
            maxi += (nba * y);
            s = reduceba(s);
        }
    }
    else
    {
        while (noofba(s) > 0)
        {
            nba = noofba(s);
            maxi += (nba * y);
            s = reduceba(s);
        }

        // now check ba in sn
        while (noofab(s) > 0)
        {
            nab = noofab(s);
            maxi += (nab * x);
            s = reduceab(s);
        }
    }

    return maxi;
}

int main()
{
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    cout << maximumGain(s, x, y);
    return 0;
}