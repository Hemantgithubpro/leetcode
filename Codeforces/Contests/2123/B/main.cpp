#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    int n, j, k;
    cin >> n >> j >> k;
    --j;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int player_j_strength = a[j];

    int num_strictly_stronger = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > player_j_strength)
        {
            num_strictly_stronger++;
        }
    }

    // If there are fewer than k players strictly stronger, player j can be in the last k
    if (num_strictly_stronger < k)
    {
        cout << "YES\n";
        return;
    }

    // If there are exactly k players strictly stronger, player j can't be in the last k
    if (num_strictly_stronger == k)
    {
        cout << "NO\n";
        return;
    }

    // Count how many players have the same strength as player j (including player j)
    int same_strength_count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == player_j_strength)
        {
            same_strength_count++;
        }
    }

    // Calculate how many spots are left for players with the same strength as player j
    int available_spots = k - num_strictly_stronger;
    
    // If there are enough spots for all same-strength players (including j), then YES
    // Otherwise, since it's random, there's a chance player j can be eliminated, so NO
    if (same_strength_count <= available_spots)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        solve();
    }

    return 0;
}
