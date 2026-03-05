#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define vsort(a) sort(a.rbegin(), a.rend())
#define toLow transform(s.begin(), s.end(), s.begin(), ::tolower)
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
using ll = long long;
using namespace std;

void solve()
{

    // 20 5 1 4 2
    // 1 2 4 5 20
    // prefix sum: 1 3 7 12 32
    // 1: 0
    // 2: 2>1 , 2+1!>4 -> 1
    // 4: 4>1, 4>2, 4+2+1>5 => 7>5 => psum[i]>b[i+1]

    ll n; cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<ll> b(a);
    sort(b.begin(),b.end());

    vector<ll> psum(n);
    psum[0]=b[0];
    for(ll i=1; i<n; i++){
        psum[i]=psum[i-1]+b[i];
    }

    unordered_map<ll,ll> um;

    for(ll i=0; i<n; i++){
        ll val=b[i];
        ll ans=i;
        ll sumtillnow=psum[i]-b[i];
        ll j=i;
        while(j<n-1 && psum[j]>=b[j+1]){
            j++;
            ans++;
        }
        um[val]=ans;
    }

    // 1:0
    // 2:1
    // 4:3
    // 5:3
    // 20:4

    for(ll i=0; i<n; i++){
        ll val=a[i];
        cout<<um[val]<<" ";
    }
    cout<<endl;
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