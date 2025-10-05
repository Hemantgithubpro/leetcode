#include <bits/stdc++.h>
using namespace std;
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
        if (l1 == l2 && l2 == l3 && l3 == b1 + b2 + b3)
        {
            cout << "YES" << endl;
        }
        else if (b1 == b2 && b2 == b3 && b3 == l1 + l2 + l3)
        {
            cout << "YES" << endl;
        }
        else if (l2 == l3 && l1 + l2 == b1 && b1 == b2 + b3)
        {
            cout << "YES" << endl;
        }
        else if (l1 == l2 + l3 && l2 + l3 == b1 + b2 && b2 == b3)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}
