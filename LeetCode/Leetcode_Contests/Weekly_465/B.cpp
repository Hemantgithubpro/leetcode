#include <bits/stdc++.h>
using namespace std;

vector<int> splitInteger(int n, int k)
{
    vector<int> d;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            if (i != n / i)
                d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());

    int md = INT_MAX;
    vector<int> bs;

    function<void(int, vector<int> &, int, int, int)> bt =
        [&](int idx, vector<int> &cur, int p, int c, int mx)
    {
        if (c == k)
        {
            if (p == n)
            {
                int mn = *min_element(cur.begin(), cur.begin() + c);
                int df = mx - mn;
                if (df < md)
                {
                    md = df;
                    bs = vector<int>(cur.begin(), cur.begin() + c);
                }
            }
            return;
        }

        if (idx >= d.size() || p > n)
            return;

        cur[c] = d[idx];
        bt(idx, cur, p * d[idx], c + 1, max(mx, d[idx]));

        bt(idx + 1, cur, p, c, mx);
    };

    vector<int> cur(k);
    bt(0, cur, 1, 0, 0);

    if (bs.empty())
    {
        bs.resize(k, 1);
        int r = n;

        while (r > 1)
        {
            int mi = min_element(bs.begin(), bs.end()) - bs.begin();

            for (int i = 2; i <= r; ++i)
            {
                if (r % i == 0)
                {
                    bs[mi] *= i;
                    r /= i;
                    break;
                }
            }
        }
    }

    return bs;
}

int main()
{
    int k = 4, n = 360;
    vector<int> a = splitInteger(n, k);
    for (int num : a)
        cout << num << " ";
}