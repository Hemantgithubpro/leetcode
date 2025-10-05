// it was really a brute force soln
// well, i saw the solution and copied it, slightly understood it.
#include <bits/stdc++.h>
using namespace std;

// bool isin(string x, string s)
// {
//     int j = 0;
//     for (int i = 0; i < x.size(); i++)
//     {
//         if (x[i] == s[j])
//         {
//             j++;
//             if (j >= s.size())
//                 return true;
//         }
//         else
//         {
//             if (x[i] == s[0])
//             {
//                 j = 1;
//             }
//             else
//             {
//                 j = 0;
//             }
//         }
//     }
//     return false;
// }

string append(string x)
{
    string y = x;
    for (int i = 0; i < x.size(); i++)
    {
        y.push_back(x[i]);
    }
    return y;
}

// there was some problem in my isin funcn above.
bool isin(string x, string s)
{
    if (x.size() < s.size())
    {
        return false;
    }
    for (int i = 0; i < x.size()-s.size()+1; i++)
    {
        if(x.substr(i,s.size())==s){
            return true;
        }
    }
    return false;
}

void solve(int n, int m, string x, string s)
{
    // max of m = 24, so n=1, append(n)=2 then 4 then 8 then 16 then 32(limit reached), max 5 append steps could happen
    string x0 = x;
    string x1 = x0 + x0;
    string x2 = x1 + x1;
    string x3 = x2 + x2;
    string x4 = x3 + x3;
    string x5 = x4 + x4;

    long long ans = -1;
    if (isin(x0, s))
        ans = 0;
    else if (isin(x1, s))
        ans = 1;
    else if (isin(x2, s))
        ans = 2;
    else if (isin(x3, s))
        ans = 3;
    else if (isin(x3, s))
        ans = 3;
    else if (isin(x4, s))
        ans = 4;
    else if (isin(x5, s))
        ans = 5;

    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        int n, m;
        cin >> n >> m;
        string x;
        cin >> x;
        string s;
        cin >> s;

        solve(n, m, x, s);
    }

    return 0;
}
