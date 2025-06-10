#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        // input
        char a[10][10];
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cin >> a[i][j];
            }
        }
        long long points = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (a[i][j] == 'X')
                {
                    if (i == 0 || i == 9 || j == 0 || j == 9)
                    {
                        points++;
                    }
                    else if (i == 4 && j == 4 || i == 5 && j == 4 || i == 4 && j == 5 || i == 5 && j == 5)
                    {
                        points += 5;
                    }
                    else if ((i > 0 && i < 9) && (j == 1 || j == 8))
                    {
                        points += 2;
                    }
                    else if ((j > 0 && j < 9) && (i == 1 || i == 8))
                    {
                        points += 2;
                    }
                    else if ((i > 1 && i < 8) && (j == 2 || j == 7))
                    {
                        points += 3;
                    }
                    else if ((j > 1 && j < 8) && (i == 2 || i == 7))
                    {
                        points += 3;
                    }
                    else if ((i > 2 && i < 7) && (j == 3 || j == 6))
                    {
                        points += 4;
                    }
                    else if ((j > 2 && j < 7) && (i == 3 || i == 6))
                    {
                        points += 4;
                    }
                }
            }
        }
        cout << points << endl;
    }

    return 0;
}
