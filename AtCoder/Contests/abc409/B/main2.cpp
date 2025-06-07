// this will be n^2

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        um[a[i]]++;
    }

    vector<pair<int, int>> vec(um.begin(), um.end());
    sort(vec.begin(), vec.end());

    um.clear();
    for (const auto &pair : vec)
    {
        um[pair.first] = pair.second;
    }

    
    int x = 0;
    int occur = 0;
    for (auto it = um.begin(); it != um.end(); it++)
    {
        occur = occur + it->second;
        // cout<<it->first<<" "<<occur<<endl;
        if (occur >= it->first)
        {
            x = max(x, it->first);
        }

        // cout<<it->first<<" "<<it->second<<endl;
    }
    cout << x;

    return 0;
}
