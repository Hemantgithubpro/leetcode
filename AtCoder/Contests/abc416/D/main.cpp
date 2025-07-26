#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N);
    multiset<ll> B;

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i)
    {
        ll b_val;
        cin >> b_val;
        B.insert(b_val);
    }

    sort(A.begin(), A.end());

    ll mini = 0;

    for (int i = 0; i < N; ++i)
    {
        ll curra = A[i];

        auto it = B.lower_bound(M - curra);

        if (it != B.end())
        {
            mini += (curra + *it) % M;
            B.erase(it);
        }
        else
        {
            it = B.begin();
            mini += (curra + *it) % M;
            B.erase(it);
        }
    }

    cout << mini << '\n';
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