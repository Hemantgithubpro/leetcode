#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    for (int i = l - 1; i < r; i++)
    {
        if (s[i] != 'o')
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    // int t;
    // cin >> t;
    // while (t--) {
    // input
    solve();
    // }

    return 0;
}
