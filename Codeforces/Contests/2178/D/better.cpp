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

struct Elf
{
    int idx;
    long long a;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Elf> elves(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> elves[i].a;
        elves[i].idx = i + 1;
    }

    // Special cases m = 0 and m = 1
    if (m == 0 || m == 1)
    {
        // Find elf with maximum attack
        int maxIdx = 0;
        for (int i = 1; i < n; ++i)
        {
            if (elves[i].a > elves[maxIdx].a)
            {
                maxIdx = i;
            }
        }

        long long sumOthers = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i != maxIdx)
            {
                sumOthers += elves[i].a;
            }
        }

        if (m == 0)
        {
            if (elves[maxIdx].a <= sumOthers)
            {
                cout << n - 1 << "\n";
                for (int i = 0; i < n; ++i)
                {
                    if (i != maxIdx)
                    {
                        cout << elves[i].idx << " " << elves[maxIdx].idx << "\n";
                    }
                }
            }
            else
            {
                cout << "-1\n";
            }
        }
        else
        { // m == 1
            if (elves[maxIdx].a > sumOthers)
            {
                cout << n - 1 << "\n";
                for (int i = 0; i < n; ++i)
                {
                    if (i != maxIdx)
                    {
                        cout << elves[i].idx << " " << elves[maxIdx].idx << "\n";
                    }
                }
            }
            else
            {
                cout << "-1\n";
            }
        }
        return;
    }

    // For m >= 2
    if (n < 2 * m)
    {
        cout << "-1\n";
        return;
    }

    // Sort elves by attack value descending
    sort(elves.begin(), elves.end(), [](const Elf &x, const Elf &y)
         { return x.a > y.a; });

    // Survivors are the first m elves
    vector<Elf> survivors(elves.begin(), elves.begin() + m);
    // Non-survivors are the rest
    vector<Elf> nonSurvivors(elves.begin() + m, elves.end());
    // Sort non-survivors by attack value ascending
    sort(nonSurvivors.begin(), nonSurvivors.end(), [](const Elf &x, const Elf &y)
         { return x.a < y.a; });

    // Each group corresponds to a survivor
    vector<vector<Elf>> groups(m);
    // Assign the smallest m non-survivors to the survivors
    // Largest survivor gets smallest non-survivor
    for (int i = 0; i < m; ++i)
    {
        groups[i].push_back(nonSurvivors[i]);
    }

    // Remaining non-survivors
    int remaining = nonSurvivors.size() - m;
    // Priority queue of (remaining capacity, survivor index)
    // We use negative capacity because we want max-heap
    priority_queue<pair<long long, int>> pq;
    for (int i = 0; i < m; ++i)
    {
        long long capacity = survivors[i].a - groups[i][0].a;
        if (capacity <= 0)
        {
            cout << "-1\n";
            return;
        }
        pq.push({capacity, i});
    }

    // Assign remaining non-survivors
    for (int i = m; i < nonSurvivors.size(); ++i)
    {
        if (pq.empty())
        {
            cout << "-1\n";
            return;
        }
        auto [cap, idx] = pq.top();
        pq.pop();
        long long newCap = cap - nonSurvivors[i].a;
        if (newCap <= 0)
        {
            cout << "-1\n";
            return;
        }
        groups[idx].push_back(nonSurvivors[i]);
        pq.push({newCap, idx});
    }

    // Output attacks
    int totalAttacks = 0;
    for (int i = 0; i < m; ++i)
    {
        totalAttacks += groups[i].size();
    }
    cout << totalAttacks << "\n";

    // For each group, first have all but one non-survivor attack the survivor,
    // then the survivor attacks the remaining non-survivor.
    for (int i = 0; i < m; ++i)
    {
        int k = groups[i].size();
        // Attacks by non-survivors (all except the last one)
        for (int j = 0; j < k - 1; ++j)
        {
            cout << groups[i][j].idx << " " << survivors[i].idx << "\n";
        }
        // Attack by survivor on the last non-survivor in the group
        cout << survivors[i].idx << " " << groups[i][k - 1].idx << "\n";
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