#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int size = 1 << n;
    vector<int> p(size);
    for (int i = 0; i < size; i++)
    {
        cin >> p[i];
    }

    function<void(int, int)> rec = [&](int l, int r) {
        if (r - l == 1) {
            return;
        }
        int mid = l + (r - l) / 2;
        rec(l, mid);
        rec(mid, r);
        if (p[l] > p[mid]) {
            for (int i = 0; i < (mid - l); ++i) {
                swap(p[l + i], p[mid + i]);
            }
        }
    };

    rec(0, size);

    for (int i = 0; i < size; i++)
    {
        cout << p[i] << (i == size - 1 ? "" : " ");
    }
    cout << "\n";
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