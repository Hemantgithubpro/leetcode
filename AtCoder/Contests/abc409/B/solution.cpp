// i'll understand it later
#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int ans = 0;
    for (int i = 0; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (A[j] >= i) cnt++;
        }
        if (cnt >= i) ans = i;
    }
    cout << ans;
}
