#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Point
{
    int x, y, oidx;
};

bool compareT0(const Point &a, const Point &b)
{
    return (a.x + a.y) < (b.x + b.y);
}

bool compareT1(const Point &a, const Point &b)
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

    vector<string> out_lines;

    while (t--)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            out_lines.push_back("");
            continue;
        }

        vector<Point> points(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> points[i].x >> points[i].y;
            points[i].oidx = i + 1;
        }

        vector<Point> points_t0 = points;
        vector<Point> points_t1 = points;

        sort(points_t0.begin(), points_t0.end(), compareT0);

        sort(points_t1.begin(), points_t1.end(), compareT1);

        ll sum_t0 = 0;
        int half = n / 2;
        for (int i = 0; i < half; ++i)
        {
            sum_t0 += (ll)(points_t0[i + half].x + points_t0[i + half].y) - (points_t0[i].x + points_t0[i].y);
        }

        ll sum_t1 = 0;
        for (int i = 0; i < half; ++i)
        {
            sum_t1 += (ll)(points_t1[i + half].x - points_t1[i + half].y) - (points_t1[i].x - points_t1[i].y);
        }

        vector<Point> *sorted_points_ptr;
        if (sum_t0 >= sum_t1)
        {
            sorted_points_ptr = &points_t1;
        }
        else
        {
            sorted_points_ptr = &points_t0;
        }

        vector<Point> &sorted_points = *sorted_points_ptr;

        for (int i = 0; i < half; ++i)
        {
            out_lines.push_back(to_string(sorted_points[i].oidx) + " " +
                                to_string(sorted_points[i + half].oidx));
        }
    }

    for (string line : out_lines)
    {
        cout << line << "\n";
    }

    return 0;
}