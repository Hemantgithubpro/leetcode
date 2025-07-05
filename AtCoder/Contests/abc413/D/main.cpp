#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, int> m_a;
    vector<long long> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m_a[a[i]]++;
        c[i] = abs(a[i]);
    }

    if (n <= 2)
    {
        cout << "Yes\n";
        return;
    }

    sort(c.begin(), c.end());

    bool is_gp = true;
    for (int i = 1; i < n - 1; ++i)
    {
        if ((long long)c[i] * c[i] != (long long)c[i - 1] * c[i + 1])
        {
            is_gp = false;
            break;
        }
    }

    if (!is_gp)
    {
        cout << "No\n";
        return;
    }

    bool found = false;
    for (int k = 0; k < 2; ++k)
    {
        if (k == 1)
        {
            if (c.front() == c.back())
                break;
            reverse(c.begin(), c.end());
        }

        map<long long, int> m_b1;
        for (long long val : c)
            m_b1[val]++;
        if (m_b1 == m_a)
        {
            found = true;
            break;
        }

        map<long long, int> m_b2;
        for (long long val : c)
            m_b2[-val]++;
        if (m_b2 == m_a)
        {
            found = true;
            break;
        }

        map<long long, int> m_b3;
        for (int i = 0; i < n; ++i)
            m_b3[i % 2 == 0 ? c[i] : -c[i]]++;
        if (m_b3 == m_a)
        {
            found = true;
            break;
        }

        map<long long, int> m_b4;
        for (int i = 0; i < n; ++i)
            m_b4[i % 2 == 0 ? -c[i] : c[i]]++;
        if (m_b4 == m_a)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

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
        solve();
    }
    return 0;
}
