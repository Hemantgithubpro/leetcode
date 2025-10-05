
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool canReach(int px, int py, int qx, int qy, const vector<int> &a)
{
    long long totalDistance = 0;
    for (int d : a)
        totalDistance += d;

    // Compute squared Euclidean distance
    long long dx = px - qx;
    long long dy = py - qy;
    long long distSquared = dx * dx + dy * dy;

    // Compare with totalDistance^2
    // We square both sides to avoid floating-point issues
    if (totalDistance * totalDistance < distSquared)
        return false;

    // Now check parity
    double actualDistance = sqrt(distSquared);
    double leftover = totalDistance - actualDistance;

    // Check if leftover is even (within floating point tolerance)
    return fmod(leftover, 2.0) < 1e-6 || fmod(leftover, 2.0) > 2.0 - 1e-6;
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
        int n, px, py, qx, qy;
        cin >> n >> px >> py >> qx >> qy;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        if (canReach(px, py, qx, qy, a))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
