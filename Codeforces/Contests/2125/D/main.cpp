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

    ll ans = 1;
    
    for (int cell = 1; cell <= m; cell++) {
        vector<int> segIds;
        for (int i = 0; i < n; i++) {
            if (l[i] <= cell && cell <= r[i]) {
                segIds.push_back(i);
            }
        }
        
        int k = segIds.size();
        if (k == 0) {
            ans = 0;
            break;
        }
        
        ll num = 0, den = 1;
        
        for (int id : segIds) {
            den = (den * q[id]) % MOD;
        }
        
        for (int i = 0; i < k; i++) {
            int id = segIds[i];
            
            ll tnum = p[id];
            ll tden = q[id];
            
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                
                int oid = segIds[j];
                ll diff = (q[oid] - p[oid] + MOD) % MOD;
                
                tnum = (tnum * diff) % MOD;
                tden = (tden * q[oid]) % MOD;
            }
            
            ll factor = (den * modInverse(tden, MOD)) % MOD;
            tnum = (tnum * factor) % MOD;
            
            num = (num + tnum) % MOD;
        }
        
        ll prob = (num * modInverse(den, MOD)) % MOD;
        ans = (ans * prob) % MOD;
    }
    
    std::cout << ans << std::endl;
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
