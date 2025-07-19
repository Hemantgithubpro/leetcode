#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Point
{
    int x, y, idx;
};

bool cmp0(const Point &a, const Point &b)
{
    return (a.x + a.y) < (b.x + b.y);
}

bool cmp1(const Point &a, const Point &b)
{
    return (a.x - a.y) < (b.x - b.y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<string> out;

    while (t--)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            out.push_back("");
            continue;
        }

        vector<Point> pts(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> pts[i].x >> pts[i].y;
            pts[i].idx = i + 1;
        }

        vector<Point> pts0 = pts;
        vector<Point> pts1 = pts;

        sort(pts0.begin(), pts0.end(), cmp0);

        sort(pts1.begin(), pts1.end(), cmp1);
        ll sum0 = 0;
        int half = n / 2;
        for (int i = 0; i < half; ++i)
        {
            sum0 += (ll)(pts0[i + half].x + pts0[i + half].y) - (pts0[i].x + pts0[i].y);
        }

        ll sum1 = 0;
        for (int i = 0; i < half; ++i)
        {
            sum1 += (ll)(pts1[i + half].x - pts1[i + half].y) - (pts1[i].x - pts1[i].y);
        }

        vector<Point> *ptr;
        if (sum0 >= sum1)
        {
            ptr = &pts1;
        }
        else
        {
            ptr = &pts0;
        }

        vector<Point> &sorted = *ptr;

        for (int i = 0; i < half; ++i)
        {
            out.push_back(to_string(sorted[i].idx) + " " + to_string(sorted[i + half].idx));
        }
    }

    for (string line : out)
    {
        cout << line << "\n";
    }

    return 0;
}