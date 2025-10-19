#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int N;
    cin >> N;
    // Read the N platform heights A_i
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    // Initialize the shortest ladder height needed to 0
    int shortest_ladder_height = 0;

    // Iterate through all adjacent pairs of platforms (i and i+1)
    // from i = 0 to N-2 in 0-indexed A.
    for (int i = 0; i < N - 1; ++i)
    {
        // Calculate the height required to move between platform i and i+1
        // This is simply the absolute difference in their heights.
        int current_gap = abs(A[i] - A[i + 1]);

        // The overall required ladder height is the maximum of all these gaps (bottleneck)
        shortest_ladder_height = max(shortest_ladder_height, current_gap);
    }

    cout << shortest_ladder_height << endl;
}

// void solve(ll n, vector<ll>& a){

// }

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
    int i = 1;
    while (t--)
    {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        cout << "Case #" << i++ << ": ";
        solve();
    }

    return 0;
}
