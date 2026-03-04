#include <bits/stdc++.h>
#include <numeric>
#define ll long long

using namespace std;

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll nextPrime(ll start)
{
    while (!isPrime(start))
        start++;
    return start;
}

void solve()
{
    // input here only
    // if a is prime, then 5 divisors, otherwise 4 divisors with atleast apart of d, starting with 1, and then ...
    // lcm of those num

    // d=3, 1...4...7...10 => lcm of 1,4,7,10:

    // d=2, 1..3..5..7 => lcm of 1,3,5,7: 105,
    // minimize value of lcm of "1" and 3 numbers, mallaining diff of atleast d.
    // 1,3,5,15

    // the fourth number is also defined, as lcm of 2nd and 3rd, and fourth - third >=d
    // just find 2nd and 3rd

    // d=4
    // 1,5,10,20

    ll d;
    cin >> d;

    ll second = nextPrime(d + 1);
    ll third = nextPrime(second + d);

    ll ans = lcm(second, third);

    // for (ll i = second; i < 10000; i++)
    // {
    //     for (ll j = third; j < 1000; j++)
    //     {
    //         ll temp = lcm(i, j);
    //         ans= min(ans,temp);
    //     }
    // }
    cout << ans << endl;
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
        // for (ll i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);

        solve();
    }

    return 0;
}
