#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    long long N, M;
        cin >> N >> M;

        string ans;
        ans.reserve(2*(N+M) - 1);

        if (N == 0) {
            ans.append(M, '>');
            if (M > 1) ans.append(M - 1, '=');
        } else if (M == 0) {
            ans.append(N, '<');
            if (N > 1) ans.append(N - 1, '=');
        } else {
            // All inserted comparators can be '<'
            ans.append(2 * N + M - 1, '<');
            ans.append(M, '>');
        }

        cout << ans << '\n';
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
