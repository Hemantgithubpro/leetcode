#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    unordered_map<char, int> frq;
    for (int i = 0; i < s.size(); i++)
    {
        frq[s[i]]++;
    }

    // to find characters with frequency odd
    int oddfrq = 0;

    for (auto it = frq.begin(); it != frq.end(); it++)
    {
        if (it->second % 2 == 1)
        {
            oddfrq++;
            it->second--;
        }
    }
    if(oddfrq>k+1) cout<<"no"<<endl;
    else cout<<"yes"<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        solve();
    }

    return 0;
}
