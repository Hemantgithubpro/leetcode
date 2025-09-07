#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n;
    cin >> n;

    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < n; i++)
    {
        int b_val;
        cin >> b_val;
        groups[b_val].push_back(i);
    }

    bool poss = true;
    for (auto &[val, idx] : groups)
    {
        if (idx.size() % val != 0)
        {
            poss = false;
            break;
        }
    }

    if (!poss)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> a(n);
    int va = 0;
    for (auto &[val, idx] : groups)
    {
        int cno = idx.size() / val;
        for (int cidx = 0; cidx < cno; cidx++)
        {
            va++;
            for (int i = 0; i < val; i++)
            {
                int org = idx[cidx * val + i];
                a[org] = va;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
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
