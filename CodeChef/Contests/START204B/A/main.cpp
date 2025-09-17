#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    if (n % 2 != 0)
    {
        cout << "No\n";
        return;
    }

    int a = 0;
    int b = 0;

    for (char c : s)
    {
        if (c == '1')
            a++;
        else
            b++;
    }

    int trgt = n / 2;

    if (a <= trgt && b <= trgt)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
