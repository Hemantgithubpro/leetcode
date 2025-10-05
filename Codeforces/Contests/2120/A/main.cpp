#include <bits/stdc++.h>
using namespace std;

bool canFormSquare(int l1, int b1, int l2, int b2, int l3, int b3)
{
    // Try all possible orientations for each rectangle
    vector<pair<int, int>> orientations1 = {{l1, b1}, {b1, l1}};
    vector<pair<int, int>> orientations2 = {{l2, b2}, {b2, l2}};
    vector<pair<int, int>> orientations3 = {{l3, b3}, {b3, l3}};

    for (auto r1 : orientations1)
    {
        for (auto r2 : orientations2)
        {
            for (auto r3 : orientations3)
            {
                int l1 = r1.first, b1 = r1.second;
                int l2 = r2.first, b2 = r2.second;
                int l3 = r3.first, b3 = r3.second;

                // Arrangement 1: Both small rectangles on top of bigger one
                // Rectangle 1 is the base, rectangles 2 and 3 are on top side by side
                if (l2 + l3 == l1 && b2 == b3 && b1 + b2 == l1)
                {
                    return true;
                }

                // Arrangement 2: Both small rectangles to the right of bigger one
                // Rectangle 1 is on left, rectangles 2 and 3 are stacked on right
                if (b2 + b3 == b1 && l2 == l3 && l1 + l2 == b1)
                {
                    return true;
                }

                // Arrangement 3: One on top, one on right (L-shape)
                // Rectangle 1 at bottom-left corner
                // Rectangle 2 spans the top (width = side of square)
                // Rectangle 3 spans the right (height = side of square)
                // They must form a perfect square
                if (l2 == l1 + l3 && b3 == b1 + b2 && l1 + l3 == b1 + b2)
                {
                    return true;
                }
            }
        }
    }

    return false;
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

    while (t--)
    {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        // Try all permutations of rectangles for each arrangement type
        bool canForm = false;

        // Try rectangle 1 as the main rectangle
        if (canFormSquare(l1, b1, l2, b2, l3, b3))
            canForm = true;

        // Try rectangle 2 as the main rectangle
        if (canFormSquare(l2, b2, l1, b1, l3, b3))
            canForm = true;

        // Try rectangle 3 as the main rectangle
        if (canFormSquare(l3, b3, l1, b1, l2, b2))
            canForm = true;

        cout << (canForm ? "YES" : "NO") << "\n";
    }

    return 0;
}