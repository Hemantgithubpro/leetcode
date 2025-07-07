#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    // input here only
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    // identify bad positions
    vector<int> bad;
    bad.reserve(n);
    for (int i = 0; i + 1 < n; i++) {
        if (b[i+1] % b[i] != 0) bad.push_back(i);
    }
    if (bad.empty()) {
        cout << 1 << '\n';
        return;
    }
    int p = bad[0];
    ll v1 = b[p], v2 = b[p+1];
    vector<ll> cand;
    auto add_divs = [&](ll v) {
        for (ll d = 1; d * d <= v; d++) {
            if (v % d == 0) {
                cand.push_back(d);
                if (d * d != v) cand.push_back(v / d);
            }
        }
    };
    add_divs(v1);
    add_divs(v2);
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    ll ans = 1;
    // helper: check candidate x
    auto valid_x = [&](ll x) {
        if (x <= 1) return false;
        // prune: x divides b[i] or b[i+1] for each bad pair
        for (int i : bad) {
            if (b[i] % x != 0 && b[i+1] % x != 0)
                return false;
        }
        // dp: possible states at i: bitmask possible f(i)
        bool ok0 = false, ok1 = false;
        // f[0]
        ok0 = true;
        ok1 = (b[0] % x == 0);
        for (int i = 0; i + 1 < n; i++) {
            bool nxt0 = false, nxt1 = false;
            for (int f = 0; f < 2; f++) {
                if ((f==0?ok0:ok1)==false) continue;
                ll ai = b[i] / (f ? x : 1);
                for (int g = 0; g < 2; g++) {
                    if (g==1 && b[i+1] % x != 0) continue;
                    ll aj = b[i+1] / (g ? x : 1);
                    if (ai > 0 && aj % ai == 0) {
                        if (g==0) nxt0 = true;
                        else nxt1 = true;
                    }
                }
            }
            if (!nxt0 && !nxt1) return false;
            ok0 = nxt0;
            ok1 = nxt1;
        }
        return (ok0 || ok1);
    };
    for (ll x : cand) {
        if (valid_x(x)) { ans = x; break; }
    }
    if (ans == 1) ans = 1;  // fallback
    cout << ans << '\n';
    return;
}

// void solve(ll n, vector<ll>& a){

// }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
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
