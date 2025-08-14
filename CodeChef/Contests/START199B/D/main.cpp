#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// A large value to signify an impossible/invalid path
const ll INF = 4e5 + 7;

// Helper function for the greedy choice at the next step
ll get_next_val(ll prev_val, ll cur_m, ll cur_M)
{
    if (cur_m > prev_val)
    {
        return cur_m;
    }
    if (cur_M > prev_val)
    {
        return cur_M;
    }
    return INF;
}

void solve()
{
    int n;
    cin >> n;

    vector<ll> m(n), M(n);
    vector<ll> a_in(n), b_in(n);

    for (int i = 0; i < n; ++i)
        cin >> a_in[i];
    for (int i = 0; i < n; ++i)
        cin >> b_in[i];

    for (int i = 0; i < n; ++i)
    {
        if (a_in[i] < b_in[i])
        {
            m[i] = a_in[i];
            M[i] = b_in[i];
        }
        else
        {
            m[i] = b_in[i];
            M[i] = a_in[i];
        }
    }

    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    int LOGN = floor(log2(n)) + 1;

    // up[k][i] stores the state after a jump of 2^k from index i.
    // The state is a pair: {value if start was m[i], value if start was M[i]}
    vector<vector<pair<ll, ll>>> up(LOGN, vector<pair<ll, ll>>(n));

    // Base case (k=0): jump of 1
    for (int i = 0; i < n - 1; ++i)
    {
        up[0][i].first = get_next_val(m[i], m[i + 1], M[i + 1]);
        up[0][i].second = get_next_val(M[i], m[i + 1], M[i + 1]);
    }
    // Cannot jump from the last element
    if (n > 0)
    {
        up[0][n - 1] = {INF, INF};
    }

    // Build sparse table
    for (int k = 1; k < LOGN; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            ll mid_idx = i + (1LL << (k - 1));

            if (mid_idx >= n)
            {
                up[k][i] = {INF, INF};
                continue;
            }

            // Calculate ending value if we start with m[i]
            ll val_m_mid = up[k - 1][i].first;
            if (val_m_mid == INF)
            {
                up[k][i].first = INF;
            }
            else
            {
                // Check against m and M at the midpoint to decide which path to follow
                if (val_m_mid < m[mid_idx])
                {
                    up[k][i].first = up[k - 1][mid_idx].first;
                }
                else if (val_m_mid < M[mid_idx])
                {
                    up[k][i].first = up[k - 1][mid_idx].second;
                }
                else
                {
                    up[k][i].first = INF;
                }
            }

            // Calculate ending value if we start with M[i]
            ll val_M_mid = up[k - 1][i].second;
            if (val_M_mid == INF)
            {
                up[k][i].second = INF;
            }
            else
            {
                if (val_M_mid < m[mid_idx])
                {
                    up[k][i].second = up[k - 1][mid_idx].first;
                }
                else if (val_M_mid < M[mid_idx])
                {
                    up[k][i].second = up[k - 1][mid_idx].second;
                }
                else
                {
                    up[k][i].second = INF;
                }
            }
        }
    }

    ll total_perfect_ranges = 0;
    for (int i = 0; i < n; ++i)
    {
        ll current_pos = i;
        ll current_val = m[i]; // Start with the minimum value at i
        ll len = 1;

        // Use binary lifting to find the length of the perfect range
        for (int k = LOGN - 1; k >= 0; --k)
        {
            if (current_pos + (1LL << k) < n)
            {
                ll next_val;
                if (current_val == m[current_pos])
                {
                    next_val = up[k][current_pos].first;
                }
                else
                {
                    next_val = up[k][current_pos].second;
                }

                if (next_val != INF)
                {
                    len += (1LL << k);
                    current_val = next_val;
                    current_pos += (1LL << k);
                }
            }
        }
        total_perfect_ranges += len;
    }

    cout << total_perfect_ranges << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
