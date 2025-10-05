#include <iostream>
#include <cmath>
using namespace std;

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
        int a, x, y;
        cin >> a >> x >> y;

        bool found = false;
        for (int bob = 1; bob <= 100; ++bob)
        {
            if (bob == a)
                continue;

            int bob_to_x = abs(bob - x);
            int alice_to_x = abs(a - x);

            int bob_to_y = abs(bob - y);
            int alice_to_y = abs(a - y);

            if (bob_to_x < alice_to_x && bob_to_y < alice_to_y)
            {
                found = true;
                break;
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}
