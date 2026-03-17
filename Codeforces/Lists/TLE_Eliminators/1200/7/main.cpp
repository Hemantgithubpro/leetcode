#include <bits/stdc++.h>
using ll = long long;
#define mod 1000000007
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define vsort(a) sort(a.rbegin(), a.rend())
#define toLow transform(s.begin(), s.end(), s.begin(), ::tolower)
#define floop(n) for (int i = 0; i < n; i++)
#define floop2(n) for (int j = 0; j < n; j++)
#define all(a) a.begin(), a.end()
#define vec(a, n) vector<int> a(n)
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N = 1e7 + 10;
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

ll calculate(vector<vector<int>> &a, int row1, int row2)
{
    int m = a[row1].size();
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += abs(a[row1][i] - a[row2][i]);
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            a[i].push_back(temp);
        }
    }

    // floop(n){
    //     asort(a[i]);
    // }

    // brute force
    // 1: 2,3,4,,,n
    // 2: 3,4,5,,,n

    ll ans = 0;
    // for(int i=0; i<n-1; i++){
    //     for(int j=i+1; j<n; j++){
    //         ans+=calculate(a,i,j);
    //     }
    // }
    // cout<<ans<<endl;

    for (int i = 0; i < m; i++)
    {
        // column m
        vector<int> col(n);
        for (int j = 0; j < n; j++)
        {
            col[j] = a[j][i];
        }
        asort(col);

        ll temp = 0;
        for (int k = 0; k < n; k++)
        {
            int val = col[k];
            // formula: add val times the index+1, and subtract val times the n-i-1
            // temp += (val * (k + 1));
            temp += 1LL * val * k;
            temp -= 1LL * val * (n - k - 1);
        }
        ans += temp;
    }
    cout << ans << endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
