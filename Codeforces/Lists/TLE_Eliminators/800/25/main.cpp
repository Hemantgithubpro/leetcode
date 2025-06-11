#include <bits/stdc++.h>
using namespace std;

void solve(int n, string &s)
{
    int l = 0;
    int r = n - 1;
    while (l <= r && ((s[l] == '1' && s[r] == '0') || (s[l] == '0' && s[r] == '1')))
    {
        // cout<<"l: "<<l<<" r:"<<r<<" ";
        l++;
        r--;
    }
    if (r < l)
        cout << 0 << endl;
    else
        cout << r - l + 1 << endl;
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
        int n;
        cin >> n;
        string s;
        cin >> s;

        solve(n, s);
    }

    return 0;
}
