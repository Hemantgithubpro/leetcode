#include <bits/stdc++.h>
using namespace std;

// this is my own solution which was initially giving error on test case 2, but then i changed isin funcn from soln, and it also got accepted.

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

string append(string x)
{
    string y = x;
    for (int i = 0; i < x.size(); i++)
    {
        y.push_back(x[i]);
    }
    return y;
}

void solve(int n, int m, string x, string s)
{
    // code
    int ans = 0;
    while (x.size() < m)
    {
        x = append(x);
        ans++;
    }

    if (isin(x, s))
        cout << ans;
    else{
        x=append(x);
        ans++;
        if(isin(x,s)) cout<<ans;
        else cout<<-1;
    }
    cout<<endl;
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
