#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define vsort(a) sort(a.rbegin(), a.rend())
#define toLow transform(s.begin(), s.end(), s.begin(), ::tolower)
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
#define floop(n) for (int i = 0; i < n; i++)
#define floop2(n) for (int j = 0; j < n; j++)
#define all(a) a.begin(), a.end()
#define vec(a, n) vector<int> a(n)
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N = 1e7 + 10;
using ll = long long;
using namespace std;

void solve()
{
     int n;
    cin >> n;
    vector<int> p(n+1);
    for (int i=1; i<=n; i++) cin >> p[i];
    string s;
    cin >> s;
    s = " " + s;
    
    vector<bool> left_smaller(n+1, false), left_larger(n+1, false);
    vector<bool> right_smaller(n+1, false), right_larger(n+1, false);
    
    int pre_min = n+1, pre_max = 0;
    for (int i=1; i<=n; i++) {
        if (i>1) {
            if (p[i] > pre_min) left_smaller[i] = true;
            if (p[i] < pre_max) left_larger[i] = true;
        }
        pre_min = min(pre_min, p[i]);
        pre_max = max(pre_max, p[i]);
    }
    
    int suf_min = n+1, suf_max = 0;
    for (int i=n; i>=1; i--) {
        if (i<n) {
            if (p[i] > suf_min) right_smaller[i] = true;
            if (p[i] < suf_max) right_larger[i] = true;
        }
        suf_min = min(suf_min, p[i]);
        suf_max = max(suf_max, p[i]);
    }
    
    vector<int> req;
    for (int i=1; i<=n; i++) {
        if (s[i] == '1') {
            if (!( (left_smaller[i] && right_larger[i]) || (left_larger[i] && right_smaller[i]) )) {
                cout << -1 << '\n';
                return;
            }
            req.push_back(i);
        }
    }
    
    if (req.empty()) {
        cout << 0 << '\n';
        return;
    }
    
    int L0 = *min_element(req.begin(), req.end());
    int R0 = *max_element(req.begin(), req.end());
    int min_val = n+1, max_val = 0;
    for (int i : req) {
        min_val = min(min_val, p[i]);
        max_val = max(max_val, p[i]);
    }
    
    int min_A0 = n+1, max_A0 = 0;
    for (int i=1; i<L0; i++) {
        min_A0 = min(min_A0, p[i]);
        max_A0 = max(max_A0, p[i]);
    }
    int min_B0 = n+1, max_B0 = 0;
    for (int i=R0+1; i<=n; i++) {
        min_B0 = min(min_B0, p[i]);
        max_B0 = max(max_B0, p[i]);
    }
    
    if ((min_A0 <= min_val && max_B0 >= max_val) || (max_A0 >= max_val && min_B0 <= min_val)) {
        int l = -1, r = -1;
        if (min_A0 <= min_val && max_B0 >= max_val) {
            for (int i=1; i<L0; i++) {
                if (p[i] <= min_val) {
                    l = i;
                    break;
                }
            }
            for (int i=R0+1; i<=n; i++) {
                if (p[i] >= max_val) {
                    r = i;
                    break;
                }
            }
        } else {
            for (int i=1; i<L0; i++) {
                if (p[i] >= max_val) {
                    l = i;
                    break;
                }
            }
            for (int i=R0+1; i<=n; i++) {
                if (p[i] <= min_val) {
                    r = i;
                    break;
                }
            }
        }
        cout << 1 << '\n';
        cout << l << " " << r << '\n';
        return;
    }
    
    int k = req.size();
    vector<int> pre_min_req(k), pre_max_req(k);
    pre_min_req[0] = p[req[0]];
    pre_max_req[0] = p[req[0]];
    for (int i=1; i<k; i++) {
        pre_min_req[i] = min(pre_min_req[i-1], p[req[i]]);
        pre_max_req[i] = max(pre_max_req[i-1], p[req[i]]);
    }
    
    vector<int> suf_min_req(k), suf_max_req(k);
    suf_min_req[k-1] = p[req[k-1]];
    suf_max_req[k-1] = p[req[k-1]];
    for (int i=k-2; i>=0; i--) {
        suf_min_req[i] = min(suf_min_req[i+1], p[req[i]]);
        suf_max_req[i] = max(suf_max_req[i+1], p[req[i]]);
    }
    
    for (int split=0; split<k-1; split++) {
        int a1 = pre_min_req[split];
        int b1 = pre_max_req[split];
        int a2 = suf_min_req[split+1];
        int b2 = suf_max_req[split+1];
        
        bool cond1 = (min_A0 <= a1 && max_B0 >= b1) || (max_A0 >= b1 && min_B0 <= a1);
        bool cond2 = (min_A0 <= a2 && max_B0 >= b2) || (max_A0 >= b2 && min_B0 <= a2);
        
        if (cond1 && cond2) {
            int l1, r1, l2, r2;
            if (min_A0 <= a1 && max_B0 >= b1) {
                for (int i=1; i<L0; i++) {
                    if (p[i] <= a1) {
                        l1 = i;
                        break;
                    }
                }
                for (int i=R0+1; i<=n; i++) {
                    if (p[i] >= b1) {
                        r1 = i;
                        break;
                    }
                }
            } else {
                for (int i=1; i<L0; i++) {
                    if (p[i] >= b1) {
                        l1 = i;
                        break;
                    }
                }
                for (int i=R0+1; i<=n; i++) {
                    if (p[i] <= a1) {
                        r1 = i;
                        break;
                    }
                }
            }
            
            if (min_A0 <= a2 && max_B0 >= b2) {
                for (int i=1; i<L0; i++) {
                    if (p[i] <= a2) {
                        l2 = i;
                        break;
                    }
                }
                for (int i=R0+1; i<=n; i++) {
                    if (p[i] >= b2) {
                        r2 = i;
                        break;
                    }
                }
            } else {
                for (int i=1; i<L0; i++) {
                    if (p[i] >= b2) {
                        l2 = i;
                        break;
                    }
                }
                for (int i=R0+1; i<=n; i++) {
                    if (p[i] <= a2) {
                        r2 = i;
                        break;
                    }
                }
            }
            
            cout << 2 << '\n';
            cout << l1 << " " << r1 << '\n';
            cout << l2 << " " << r2 << '\n';
            return;
        }
    }
    
    vector<pair<int, int>> candidates;
    candidates.push_back({1, n});
    
    int i_min = -1, i_max = -1;
    for (int i=1; i<=n; i++) {
        if (p[i] == 1) i_min = i;
        if (p[i] == n) i_max = i;
    }
    
    if (i_min != -1) {
        if (1 < i_min) candidates.push_back({1, i_min});
        if (i_min < n) candidates.push_back({i_min, n});
    }
    if (i_max != -1) {
        if (1 < i_max) candidates.push_back({1, i_max});
        if (i_max < n) candidates.push_back({i_max, n});
    }
    
    int candidate_l1 = -1, candidate_l2 = -1;
    for (int i=1; i<L0; i++) {
        if (candidate_l1 == -1 || p[i] < p[candidate_l1]) candidate_l1 = i;
        if (candidate_l2 == -1 || p[i] > p[candidate_l2]) candidate_l2 = i;
    }
    int candidate_r1 = -1, candidate_r2 = -1;
    for (int i=R0+1; i<=n; i++) {
        if (candidate_r1 == -1 || p[i] < p[candidate_r1]) candidate_r1 = i;
        if (candidate_r2 == -1 || p[i] > p[candidate_r2]) candidate_r2 = i;
    }
    
    if (candidate_l1 != -1) {
        if (candidate_r1 != -1) candidates.push_back({candidate_l1, candidate_r1});
        if (candidate_r2 != -1) candidates.push_back({candidate_l1, candidate_r2});
    }
    if (candidate_l2 != -1) {
        if (candidate_r1 != -1) candidates.push_back({candidate_l2, candidate_r1});
        if (candidate_r2 != -1) candidates.push_back({candidate_l2, candidate_r2});
    }
    
    set<pair<int, int>> candidate_set;
    for (auto op : candidates) {
        if (op.first < op.second) {
            candidate_set.insert(op);
        }
    }
    candidates.assign(candidate_set.begin(), candidate_set.end());
    
    int m = candidates.size();
    vector<pair<int, int>> best_ops;
    bool found = false;
    for (int bit=1; bit < (1<<m); bit++) {
        vector<pair<int, int>> ops;
        for (int i=0; i<m; i++) {
            if (bit & (1<<i)) {
                ops.push_back(candidates[i]);
            }
        }
        if (ops.size() > 5) continue;
        
        bool valid = true;
        for (int i : req) {
            bool covered = false;
            for (auto op : ops) {
                int l = op.first, r = op.second;
                if (l < i && i < r) {
                    int low = min(p[l], p[r]);
                    int high = max(p[l], p[r]);
                    if (p[i] > low && p[i] < high) {
                        covered = true;
                        break;
                    }
                }
            }
            if (!covered) {
                valid = false;
                break;
            }
        }
        if (valid) {
            best_ops = ops;
            found = true;
            break;
        }
    }
    
    if (found) {
        cout << best_ops.size() << '\n';
        for (auto op : best_ops) {
            cout << op.first << " " << op.second << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}