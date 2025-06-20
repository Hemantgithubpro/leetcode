#include <bits/stdc++.h>
using namespace std;

// soln from yt
void solve(int n, vector<int> &a)
{
    vector<int> b;
    vector<int> c;

    int maxi=*max_element(a.begin(),a.end());
    
    for (int i = 0; i < n; i++)
    {
        if(a[i]!=maxi) b.push_back(a[i]);
        else c.push_back(a[i]);
    }

    if (b.size() == 0 || c.size() == 0)
        cout << -1 << endl;
    else
    {

        cout << b.size() << " " << c.size() << endl;
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < c.size(); i++)
        {
            cout << c[i] << " ";
        }
        cout<<endl;
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

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(n, a);
    }

    return 0;
}
