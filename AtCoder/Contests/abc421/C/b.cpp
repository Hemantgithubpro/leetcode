#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Count adjacent identical pairs
    int adjacent_pairs = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        if (s[i] == s[i + 1]) {
            adjacent_pairs++;
        }
    }

    cout << adjacent_pairs << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
