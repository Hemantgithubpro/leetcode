#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    
    // For each k from 1 to n
    for (int k = 1; k <= n; k++) {
        ll maxStay = 0;
        
        // Try all possible ways to pair the 2n timestamps into n pairs
        // Each pair represents (entrance_time, exit_time) for one visitor
        function<void(vector<bool>&, vector<pair<int, int>>&, ll)> backtrack = 
            [&](vector<bool>& used, vector<pair<int, int>>& pairs, ll currentStay) {
            if ((int)pairs.size() == n) {
                // We have n pairs, check if they satisfy capacity constraint
                vector<pair<ll, int>> events;
                for (auto& p : pairs) {
                    events.push_back({a[p.first], 1});   // entrance
                    events.push_back({a[p.second], -1}); // exit
                }
                
                sort(events.begin(), events.end(), [](const pair<ll, int>& x, const pair<ll, int>& y) {
                    if (x.first == y.first) return x.second < y.second; // exits before entrances
                    return x.first < y.first;
                });
                
                int currentPeople = 0;
                bool valid = true;
                for (auto& event : events) {
                    currentPeople += event.second;
                    if (currentPeople > k) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    maxStay = max(maxStay, currentStay);
                }
                return;
            }
            
            // Find next unused timestamp to start a new pair
            int start = -1;
            for (int i = 0; i < 2 * n; i++) {
                if (!used[i]) {
                    start = i;
                    break;
                }
            }
            
            if (start == -1) return;
            
            used[start] = true;
            
            // Try pairing with each later unused timestamp
            for (int end = start + 1; end < 2 * n; end++) {
                if (!used[end]) {
                    used[end] = true;
                    pairs.push_back({start, end});
                    backtrack(used, pairs, currentStay + a[end] - a[start]);
                    pairs.pop_back();
                    used[end] = false;
                }
            }
            
            used[start] = false;
        };
        
        vector<bool> used(2 * n, false);
        vector<pair<int, int>> pairs;
        backtrack(used, pairs, 0);
        
        cout << maxStay;
        if (k < n) cout << " ";
    }
    cout << "\n";
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
