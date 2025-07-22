#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 998244353;

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll a, ll p) {
    return power(a, p - 2, p);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n);
    vector<ll> p(n), q(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
    }

    vector<vector<pair<ll, ll>>> cellSegs(m + 1);
    for (int i = 0; i < n; i++) {
        for (int c = l[i]; c <= r[i]; c++) {
            cellSegs[c].push_back({p[i], q[i]});
        }
    }

    ll resNum = 1, resDen = 1;
    
    for (int c = 1; c <= m; c++) {
        auto& segs = cellSegs[c];
        int k = segs.size();
        
        if (k == 0) {
            resNum = 0;
            break;
        }
        
        ll cellNum = 0, cellDen = 1;
        
        for (auto& [p, q] : segs) {
            cellDen = (cellDen * q) % MOD;
        }
        
        for (int i = 0; i < k; i++) {
            ll pi = segs[i].first;
            ll qi = segs[i].second;
            
            ll termNum = pi;
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                
                ll pj = segs[j].first;
                ll qj = segs[j].second;
                
                termNum = (termNum * (qj - pj)) % MOD;
            }
            
            // Convert to common denominator
            for (int j = 0; j < k; j++) {
                if (i != j) {
                    termNum = (termNum * modInverse(segs[j].second, MOD)) % MOD;
                }
            }
            
            cellNum = (cellNum + termNum) % MOD;
        }
        
        resNum = (resNum * cellNum) % MOD;
        resDen = (resDen * cellDen) % MOD;
    }
    
    ll ans = (resNum * modInverse(resDen, MOD)) % MOD;
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
