#include <bits/stdc++.h>
using namespace std;

struct Point
{
    long long key; // x + y for sorting
    int x, y, idx;
};

bool compare(const Point &a, const Point &b)
{
    return a.key < b.key;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int test = 0; test < t; ++test)
    {
        int n;
        cin >> n;

        vector<Point> points(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> points[i].x >> points[i].y;
            points[i].idx = i + 1;
            points[i].key = (long long)points[i].x + points[i].y;
        }

        sort(points.begin(), points.end(), compare);

        for (int i = 0; i < n / 2; i++)
        {
            cout << points[i].idx << " " << points[n - 1 - i].idx << "\n";
        }
    }

    return 0;
}
