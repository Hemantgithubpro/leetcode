
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n;
    cin >> n;
    unordered_map<int, string> um;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        um.insert({i + 1, s});
    }
    int x;
    cin >> x;
    string y;
    cin >> y;
    if (um.count(x) && um[x] == y)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
