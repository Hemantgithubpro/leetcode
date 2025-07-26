#include <bits/stdc++.h>
using namespace std;

// brute force
void solve()
{
    int N, K, X;
    cin >> N >> K >> X;
    vector<string> words(N);
    for (int i = 0; i < N; i++)
        cin >> words[i];

    int total = 1;
    for (int i = 0; i < K; i++)
        total *= N;

    vector<string> all;
    for (int i = 0; i < total; i++)
    {
        vector<int> seq(K);
        int temp = i;
        for (int j = K - 1; j >= 0; j--)
        {
            seq[j] = temp % N;
            temp /= N;
        }
        string s;
        for (int j = 0; j < K; j++)
            s += words[seq[j]];

        all.push_back(s);
    }

    sort(all.begin(), all.end());
    cout << all[X - 1] << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    // input
    solve();
    // }

    return 0;
}
