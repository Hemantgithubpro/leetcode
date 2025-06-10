#include <bits/stdc++.h>
using namespace std;

bool sorted(int n, vector<int> &a)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
            return false;
    }
    return true;
}

void solve(int n, vector<int> &a)
{
    // code
    for (int j = 0; j < n; j++)
    {   
        if(sorted(n,a)){
            cout<<"YES"<<endl;
            return;
        }
        for (int i = 1; i < n-1; i++)
        {
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
            swap(a[i], a[i + 1]);
        }
        if(sorted(n,a)){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
