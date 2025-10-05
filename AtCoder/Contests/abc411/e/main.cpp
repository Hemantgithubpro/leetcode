#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A, B;
map<tuple<int, int, int>, int> memo;
int solve(int i, int h, int m)
{
    // Base case: all monsters defeated
    if (i == N)
    {
        return 0;
    }

    // Check if already computed
    auto key = make_tuple(i, h, m);
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    int result = 0;

    // Option 1: Fight without using magic
    if (h >= A[i])
    {
        result = max(result, 1 + solve(i + 1, h - A[i], m));
    }

    // Option 2: Fight using magic
    if (m >= B[i])
    {
        result = max(result, 1 + solve(i + 1, h, m - B[i]));
    }
    // Store and return result
    memo[key] = result;
    return result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, M;
    cin >> N >> H >> M;

    A.resize(N);
    B.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }

    cout << solve(0, H, M) << endl;
    return 0;
}
