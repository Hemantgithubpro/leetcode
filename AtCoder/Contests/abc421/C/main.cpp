#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    string s;
    cin >> N >> s;

    vector<int> a;
    for (int i = 0; i < 2 * N; i++)
    {
        if (s[i] == 'A')
            a.push_back(i);
    }

    long long cost1 = 0;
    long long cost2 = 0;
    for (int i = 0; i < N; i++)
    {
        cost1 += abs(a[i] - 2 * i);
        cost2 += abs(a[i] - (2 * i + 1));
    }

    cout << min(cost1, cost2) << endl;
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
