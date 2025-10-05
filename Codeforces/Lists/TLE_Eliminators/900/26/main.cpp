#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// one of the easiest.
void solve()
{
    ll n;
    cin >> n;
    // one approach is if it has any prime divisor, another approach is brute force, another approach is to divide it by 2 until it can't and then check if its '1' left or anything larger.

    if (n % 2)
    {
        cout << "YES" << endl;
        return;
    }

    while (n % 2 == 0 && n > 0)
    {
        n = n / 2;
    }
    if (n != 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    // lets try brute force, and if any tle comes, i'll try prime divisor approach
    // for(ll i=3; i<n; i+=2){

    // }
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
