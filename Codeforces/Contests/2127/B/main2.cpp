#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;

        x--;
        bool canEscapeLeft = true, canEscapeRight = true;

        for (int i = 0; i < x; i++)
        {
            if (s[i] == '#')
            {
                canEscapeLeft = false;
                break;
            }
        }

        for (int i = x + 1; i < n; i++)
        {
            if (s[i] == '#')
            {
                canEscapeRight = false;
                break;
            }
        }

        if (canEscapeLeft || canEscapeRight)
        {
            cout << 1 << "\n";
            continue;
        }

        int distLeft = x + 1;  
        int distRight = n - x; 

        int wallsLeft = 0, wallsRight = 0;
        for (int i = 0; i < x; i++)
        {
            if (s[i] == '#')
                wallsLeft++;
        }
        for (int i = x + 1; i < n; i++)
        {
            if (s[i] == '#')
                wallsRight++;
        }

        bool goLeft = (distLeft <= distRight);

        if (goLeft)
        {

            int days = max(wallsLeft, distLeft - 1) + 1;
            cout << days << "\n";
        }
        else
        {

            int days = max(wallsRight, distRight - 1) + 1;
            cout << days << "\n";
        }
    }

    return 0;
}