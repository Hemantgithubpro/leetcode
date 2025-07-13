#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

ll N, M;
vector<ll> X;
vector<ll> dp;
vector<ll> k_stations;

// Calculates the integer signal strength for a block of houses
ll cost(int j, int i)
{
    if (j > i)
    {
        return 0;
    }
    ll diff = X[i] - X[j];
    // Equivalent to ceil((double)diff / 2.0)
    return diff / 2 + (diff % 2);
}

// Solves the DP for a fixed penalty using Divide and Conquer Optimization
void compute(int L, int R, int optL, int optR, ll penalty)
{
    if (L > R)
    {
        return;
    }

    int mid = L + (R - L) / 2;
    ll min_val = -1;
    int opt_j = -1;

    int j_end = min(mid - 1, optR);
    for (int j = optL; j <= j_end; ++j)
    {
        ll current_val = dp[j] + cost(j, mid - 1);

        if (opt_j == -1 || current_val < min_val)
        {
            min_val = current_val;
            opt_j = j;
        }
    }

    dp[mid] = min_val + penalty;
    k_stations[mid] = k_stations[opt_j] + 1;

    compute(L, mid - 1, optL, opt_j, penalty);
    compute(mid + 1, R, opt_j, optR, penalty);
}

// Returns {number_of_stations, penalized_cost}
pair<ll, ll> check(ll penalty)
{
    // dp[i] = min penalized cost to cover houses 0..i-1
    // k_stations[i] = stations used for that dp[i]
    dp.assign(N + 1, 0);
    k_stations.assign(N + 1, 0);

    // Iterative implementation of the Divide and Conquer DP
    // This avoids stack overflow for large N.
    // Each element is {L, R, optL, optR} for a subproblem.
    vector<tuple<int, int, int, int>> stack;
    stack.emplace_back(1, N, 0, N - 1);

    while (!stack.empty())
    {
        auto [L, R, optL, optR] = stack.back();
        stack.pop_back();

        if (L > R)
        {
            continue;
        }

        int mid = L + (R - L) / 2;
        ll min_val = -1;
        int opt_j = -1;

        int j_end = min(mid - 1, optR);
        for (int j = optL; j <= j_end; ++j)
        {
            ll current_val = dp[j] + cost(j, mid - 1);
            if (opt_j == -1 || current_val < min_val)
            {
                min_val = current_val;
                opt_j = j;
            }
        }

        dp[mid] = min_val + penalty;
        k_stations[mid] = k_stations[opt_j] + 1;

        // Push subproblems onto our manual stack
        // Left part
        stack.emplace_back(L, mid - 1, optL, opt_j);
        // Right part
        stack.emplace_back(mid + 1, R, opt_j, optR);
    }

    return {k_stations[N], dp[N]};
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    X.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    N = X.size();

    if (M >= N)
    {
        cout << 0 << endl;
        return 0;
    }

    ll low = 0, high = X.back() - X.front();
    ll best_penalty = 0;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid).first <= M)
        {
            best_penalty = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    pair<ll, ll> final_res = check(best_penalty);
    ll final_penalized_cost = final_res.second;

    cout << final_penalized_cost - M * best_penalty << endl;

    return 0;
}