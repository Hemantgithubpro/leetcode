#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int a, b;
    ll x, y;
    cin >> a >> b >> x >> y;

    const int MAX_VAL = 205;

    vector<ll> dist(MAX_VAL, LLONG_MAX);

    queue<int> q;

    vector<bool> in_queue(MAX_VAL, false);

    dist[a] = 0;
    q.push(a);
    in_queue[a] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        int v1 = u + 1;
        if (v1 < MAX_VAL)
        {
            if (dist[u] != LLONG_MAX && dist[u] + x < dist[v1])
            {
                dist[v1] = dist[u] + x;
                if (!in_queue[v1])
                {
                    q.push(v1);
                    in_queue[v1] = true;
                }
            }
        }

        int v2 = u ^ 1;
        if (v2 >= 0 && v2 < MAX_VAL)
        {
            if (dist[u] != LLONG_MAX && dist[u] + y < dist[v2])
            {
                dist[v2] = dist[u] + y;
                if (!in_queue[v2])
                {
                    q.push(v2);
                    in_queue[v2] = true;
                }
            }
        }
    }

    if (dist[b] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[b] << endl;
    }
}

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
