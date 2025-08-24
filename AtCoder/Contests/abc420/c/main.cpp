#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if (!(cin >> n >> q))
        return 0;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int S = 1;
    while (S < n)
        S <<= 1;
    vector<ll> t(2 * S);
    for (int i = 0; i < n; i++)
        t[S + i] = min(a[i], b[i]);
    for (int i = S - 1; i >= 1; i--)
        t[i] = t[i << 1] + t[i << 1 | 1];
    while (q--)
    {
        char c;
        int x;
        ll v;
        cin >> c >> x >> v;
        --x;
        if (c == 'A')
            a[x] = v;
        else
            b[x] = v;
        int p = S + x;
        t[p] = min(a[x], b[x]);
        for (p >>= 1; p; p >>= 1)
            t[p] = t[p << 1] + t[p << 1 | 1];
        cout << t[1] << endl;
    }
}
