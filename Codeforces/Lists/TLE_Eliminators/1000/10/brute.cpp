#include <bits/stdc++.h>
#define ll long long

using namespace std;
// tle
void solve()
{
    // input here only
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;

    if (c == 'g')
    {
        cout << 0 << endl;
        return;
    }
    // // step 1: find all the occurence of 'c' in s, i can store it in an array
    // vector<int> allc;
    // for (int i = 0; i < n; i++)
    // {
    //     if (s[i] == 'c')
    //         allc.push_back(i);
    // }

    // int maxi = 0;
    // // step 2: now finding all next occurence of 'g' just after 'c'.
    // for (int i = 0; i < allc.size(); i++)
    // {
    //     int j = allc[i] + 1;
    //     while (j < n && s[j] != 'g')
    //         j++;
    //     if (j == 'g')
    //         maxi = max(maxi, j - allc[i]);
    // }
    // step 1: find all the occurence of 'c' in s, i can store it in an array
    int maxi = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (s[i] == c)
    //     {
    //         // finding next occurence of 'g'
    //         int j = i + 1;
    //         while (s[j] != 'g')
    //             j = (j + 1) % n;
    //         if (s[j] == 'g')
    //         {
    //             maxi = max(maxi, j - i);
    //             j = i + 1;
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {

            int steps = 1;
            int j = (i + 1) % n;
            while (s[j] != 'g')
            {
                j = (j + 1) % n;
                steps++;
            }
            maxi = max(maxi, steps);
        }
    }

    cout << maxi << endl;
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
