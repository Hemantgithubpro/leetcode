#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    //  ll N, M;
    //         cin >> N >> M;

    //         string out;
    //         if (N > 0) {
    //             out.push_back('<');                // first leaf
    //             for (ll i = 0; i < M; ++i)  // place all '>' leaves next
    //                 out += "<>";
    //             for (ll i = 0; i < N - 1; ++i) // then remaining '<' leaves
    //                 out += "=<";
    //         } else { // N == 0
    //             out.push_back('>');                // first leaf
    //             for (ll i = 0; i < M - 1; ++i)
    //                 out += "=>";
    //         }
    //         cout << out << '\n';
    long long N, M;
    cin >> N >> M;

    string out;
    out.reserve(2 * (N + M) - 1);

    if (M == 0)
    {
        // Only '<' leaves -> all operators can be '<'
        for (long long i = 0; i < 2 * N - 1; ++i)
            out.push_back('<');
    }
    else if (N == 0)
    {
        // Only '>' leaves
        if (M == 1)
        {
            out.push_back('>');
        }
        else
        {
            out.push_back('>');
            for (long long i = 0; i < M - 1; ++i)
            {
                out.push_back('=');
                out.push_back('>');
            }
        }
    }
    else
    {
        // Both present: prefix of 2N '<', then alternate starting with '>' for 2M-1 chars
        for (long long i = 0; i < 2 * N; ++i)
            out.push_back('<');
        for (long long i = 0; i < 2 * M - 1; ++i)
        {
            out.push_back((i % 2 == 0) ? '>' : '<');
        }
    }

    cout << out << '\n';
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
