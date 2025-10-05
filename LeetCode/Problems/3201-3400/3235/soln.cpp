#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUpar(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = findUpar(parent[u]);
    }

    void dsu(int u, int v)
    {
        int ulpu = findUpar(u);
        int ulpv = findUpar(v);
        if (ulpv == ulpu)
        {
            return;
        }
        if (size[ulpu] < size[ulpv])
        {
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
        else
        {
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
};

bool canReachCorner(int X, int Y, vector<vector<int>> &circles)
{
    int n = circles.size();
    DisjointSet ds(n + 5);

    // Special nodes for boundaries
    int leftBoundary = n + 3;
    int topBoundary = n;
    int rightBoundary = n + 1;
    int bottomBoundary = n + 2;

    int i = 0;
    for (auto it : circles)
    {
        int xi = it[0], yi = it[1], ri = it[2];
        if (yi - ri >= Y || xi - ri >= X)
        {
            continue;
        }
        if (((xi > (X + Y) || yi > Y) && (xi > X || yi > X + Y)))
        {
            continue;
        }
        if (xi <= ri)
        {
            ds.dsu(i, leftBoundary);
        }
        if (yi <= ri)
        {
            ds.dsu(i, topBoundary);
        }
        if (X - xi <= ri)
        {
            ds.dsu(i, rightBoundary);
        }
        if (Y - yi <= ri)
        {
            ds.dsu(i, bottomBoundary);
        }
        i++;
    }

    // Union circles that overlap
    i = 0;
    for (int i = 0; i < n; i++)
    {
        int x1 = circles[i][0];
        int y1 = circles[i][1];
        int r1 = circles[i][2];
        if (y1 - r1 >= Y || x1 - r1 >= X)
        {
            continue;
        }
        if (((x1 > (X + Y) || y1 > Y) && (x1 > X || y1 > X + Y)))
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            int x2 = circles[j][0];
            int y2 = circles[j][1];
            int r2 = circles[j][2];
            double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            if (dist <= (r1 + r2))
            {
                ds.dsu(i, j);
            }
        }
    }

    // Check if left is connected to right or top is connected to bottom
    if (ds.findUpar(leftBoundary) == ds.findUpar(rightBoundary) || ds.findUpar(leftBoundary) == ds.findUpar(topBoundary))
    {
        return false;
    }
    if (ds.findUpar(bottomBoundary) == ds.findUpar(rightBoundary) || ds.findUpar(bottomBoundary) == ds.findUpar(topBoundary))
    {
        return false;
    }

    return true;
}