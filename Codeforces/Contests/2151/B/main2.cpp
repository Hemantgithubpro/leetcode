#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    // std::set is efficient for storing sorted unique black cells and finding
    // the next black cell (upper_bound).
    set<ll> black_cells;
    for (int i = 0; i < m; ++i)
    {
        ll val;
        cin >> val;
        black_cells.insert(val);
    }

    // The set of black cells grows as each person finishes their task.
    // We simulate person by person, updating the single set of black cells.
    for (int i = 1; i <= n; ++i)
    { // Person 'i'
        ll current_pos = 1;

        // Person 'i' executes the first 'i' commands from the string 's'.
        for (int j = 0; j < i; ++j)
        {
            char command = s[j];

            if (command == 'A')
            {
                // Command 'A': Move to the next cell.
                current_pos++;
            }
            else
            { // Command 'B'
                // Command 'B': Move to the next white cell.

                // Find the first black cell strictly greater than current_pos.
                auto it = black_cells.upper_bound(current_pos);
                ll next_candidate = current_pos + 1;

                if (it == black_cells.end() || *it > next_candidate)
                {
                    // Case 1: The cell immediately after current_pos is white
                    // because there are no more black cells, or the next one
                    // is not adjacent.
                    current_pos = next_candidate;
                }
                else
                {
                    // Case 2: The cell immediately after is black. This is the
                    // start of a contiguous block of black cells.
                    // We need to find the end of this block to jump over it.
                    ll block_end = *it;
                    it++;
                    while (it != black_cells.end() && *it == block_end + 1)
                    {
                        block_end = *it;
                        it++;
                    }
                    current_pos = block_end + 1;
                }
            }
        }
        // The person has finished their journey. Color their final cell black.
        black_cells.insert(current_pos);
    }

    // Output the final state of the black cells.
    cout << black_cells.size() << endl;
    bool first = true;
    for (ll cell : black_cells)
    {
        if (!first)
        {
            cout << " ";
        }
        cout << cell;
        first = false;
    }
    cout << endl;
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
