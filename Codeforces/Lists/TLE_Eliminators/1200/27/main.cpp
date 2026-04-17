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
#define vec(a, n) vector<ll> a(n)
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

void solve()
{
    // save all the bits idx of the prefix which should be flipped
    // then either flip them or not and check if its same for that region of idx.
    // repeat from further most prefix to closest one(first)

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<bool> canFlip(n);

    int count0 = 0, count1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }

        if (count0 == count1)
            canFlip[i] = true;
    }

    bool isFlipped = false;

    bool isPoss = true;

    for (int i = n - 1; i >= 0; i--)
    {
        if (isFlipped == false)
        {

            if (a[i] != b[i])
            {
                if (canFlip[i])
                {
                    isFlipped ^= true;
                }
                else
                {
                    isPoss = false;

                    break;
                }
            }
        }
        else
        {

            if (a[i] == b[i])
            {
                if (canFlip[i])
                {
                    isFlipped ^= true;
                }
                else
                {
                    isPoss = false;

                    break;
                }
            }
        }
    }

    if (isPoss)
    {
        yes;
    }
    else
    {
        no;
    }
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
