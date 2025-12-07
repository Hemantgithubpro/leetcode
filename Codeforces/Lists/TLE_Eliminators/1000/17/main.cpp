#include <bits/stdc++.h>
#define ll long long

using namespace std;

// i hate bit manipulation
void solve()
{
    // input here only
    // construction cost max of p[i]^p[i+1]
    // finding permutation/sequence which minimizes the cost
    // properties of xor:
    // a ^ 0 = a
    // a ^ a = 0
    // a ^ b = b ^ a (commutative)
    // (a ^ b) ^ c = a ^ (b ^ c) (associative)
    // a ^ (b ^ c) = (a ^ b) ^ c
    // a ^ b ^ a = b (self-inverse)
    int n;
    cin >> n;

    // brute force, but tle
    // vector<int> a(n);
    // iota(a.begin(), a.end(), 0);
    // sort(a.begin(), a.end());
    // vector<int> best_perm = a;
    // int min_cost = INT_MAX;
    // do
    // {
    //     int cost = 0;
    //     for (int i = 0; i < n - 1; ++i)
    //     {
    //         cost = max(cost, a[i] ^ a[i + 1]);
    //     }
    //     if (cost < min_cost)
    //     {
    //         min_cost = cost;
    //         best_perm = a;
    //     }
    // } while (next_permutation(a.begin(), a.end()));

    // for (int x : best_perm)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    n--;
    int msb = log2(n);
    vector<int> ans;
    int num = pow(2, msb) - 1;
    while (num>=0)
    {
        ans.push_back(num);
        num--;
    }
    num = pow(2, msb);
    while (num <= n)
    {
        ans.push_back(num);
        num++;
    }
    for (auto it : ans)
        cout << it << " ";
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
