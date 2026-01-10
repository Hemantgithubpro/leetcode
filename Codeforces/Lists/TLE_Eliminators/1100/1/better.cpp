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

// Erase First or Second Letter
// BFS to collect all distinct strings reachable by repeatedly deleting index 0 or 1.
// Memory-efficient: single set tracks both visited states and final results.
void slv(const string &s, unordered_set<string> &all_strings)
{
    unordered_set<string> visited;
    queue<string> q;
    q.push(s);
    visited.insert(s);
    all_strings.insert(s);

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        if (curr.size() > 1)
        {
            // remove first character
            string t1 = curr.substr(1);
            if (visited.find(t1) == visited.end())
            {
                visited.insert(t1);
                all_strings.insert(t1);
                q.push(t1);
            }

            // remove second character
            string t2 = curr;
            t2.erase(1, 1);
            if (visited.find(t2) == visited.end())
            {
                visited.insert(t2);
                all_strings.insert(t2);
                q.push(t2);
            }
        }
    }
}

void solve()
{
    // remove first, or second
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<string> all_strings;
    slv(s, all_strings);
    cout << all_strings.size() << endl;
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