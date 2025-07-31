#include <bits/stdc++.h>
#define ll long long

using namespace std;

int find(vector<int> &parent, int x)
{
    vector<int> stack;
    while (parent[x] != x)
    {
        stack.push_back(x);
        x = parent[x];
    }
    int root = x;
    for (int y : stack)
    {
        parent[y] = root;
    }
    return root;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back(make_tuple(b, a, i + 1));
    }
    
    sort(edges.begin(), edges.end());
    
    int total_nodes = 2 * n;
    vector<int> parent(total_nodes + 1);
    for (int i = 0; i <= total_nodes; i++)
    {
        parent[i] = i;
    }
    
    vector<bool> covered(total_nodes + 2, false);
    vector<int> selected;
    
    for (const auto &edge : edges)
    {
        int b_val = get<0>(edge);
        int a_val = get<1>(edge);
        int idx = get<2>(edge);
        
        int u = a_val;
        int v = b_val;
        int ru = find(parent, u);
        int rv = find(parent, v);
        
        if (ru == rv)
        {
            continue;
        }
        
        int new_cover_count = 0;
        for (int x = a_val; x < b_val; x++)
        {
            if (!covered[x])
            {
                covered[x] = true;
                new_cover_count++;
            }
        }
        
        ru = find(parent, u);
        rv = find(parent, v);
        if (ru != rv)
        {
            parent[rv] = ru;
        }
        
        selected.push_back(idx);
    }
    
    sort(selected.begin(), selected.end());
    cout << selected.size() << endl;
    if (!selected.empty())
    {
        for (int i = 0; i < selected.size(); i++)
        {
            cout << selected[i];
            if (i < selected.size() - 1) cout << " ";
        }
        cout << endl;
    }
    else
    {
        cout << endl;
    }
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
