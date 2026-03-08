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
    int n, x;
    cin >> n >> x;
    // vec(a, n);
    // cin(a, n);
    // vec(b, n);
    // cin(b, n);
    // vec(c, n);
    // cin(c, n);

    // stack<int> as,bs,cs;
    // for(int i=n-1; i>=0; i--){
    //     as.push(a[i]);
    //     bs.push(b[i]);
    //     cs.push(c[i]);
    // }

    // int know=0;

    // while(know<=x){
    //     if(know==x){
    //         yes; return;
    //     }
    //     int av=as.top();
    //     int bv=bs.top();
    //     int bv=bs.top();

    // }
    // if(know>x) no;

    vector<int> pre[3];

    // Iterate over each stack
    for (int i = 0; i < 3; i++)
    {                        // Loop for 3 stacks
        int s = 0;           // Initialize current OR result
        pre[i].push_back(s); // Start with 0 OR result

        // Read each book's difficulty in the stack
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;

            // If adding this book changes the OR result, update it
            if ((s | a) != s)
            {
                s |= a;
                pre[i].push_back(s);
            }
        }
    }

    bool ans = false; // Flag to check if x can be achieved

    // Check all combinations of OR results from the three stacks
    for (int A : pre[0])
    { // Iterate over precomputed OR results of stack 1
        for (int B : pre[1])
        { // Iterate over precomputed OR results of stack 2
            for (int C : pre[2])
            { // Iterate over precomputed OR results of stack 3
                // Check if the combined OR result equals x
                if ((A | B | C) == x)
                {
                    ans = true;
                }
            }
        }
    }

    // Output the result for the current test case
    cout << (ans ? "YES\n" : "NO\n");
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