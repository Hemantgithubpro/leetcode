#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    // input here only
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    vector<int> ans(n + 1, 0);
    int mid = (n + 1) / 2;
    ans[mid] = a[0].second + 1;

    int left = mid - 1;
    int right = mid + 1;
    bool placeRight = true;

    for (int i = 1; i < n; ++i)
    {
        if (placeRight && right <= n)
        {
            ans[right++] = a[i].second + 1;
        }
        else if (left >= 0)
        {
            ans[left--] = a[i].second + 1;
        }
        else
        {
            ans[right++] = a[i].second + 1;
        }
        placeRight = !placeRight;
    }

    for (int i = 0; i <= n; i++)
    {
        cout << ans[i] << " ";
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
