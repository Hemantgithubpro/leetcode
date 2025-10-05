#include <bits/stdc++.h>
using namespace std;

// this is my approach after watching half of the soln, but i missedsomething.
void solve()
{
    // code
    int a, b;
    cin >> a >> b;
    // a in one direc and b in other

    int xk, yk;
    cin >> xk >> yk;
    int xq, yq;
    cin >> xq >> yq;
    // coordinated of king and queen

    // positions of knight which can attack king
    vector<pair<int, int>> king; // pair<int,int> king= (x1,y1) ...
    king.push_back({xk + a, yk + b});
    king.push_back({xk + a, yk - b});
    king.push_back({xk - a, yk + b});
    king.push_back({xk - a, yk - b});
    king.push_back({xk + b, yk + a});
    king.push_back({xk + b, yk - a});
    king.push_back({xk - b, yk + a});
    king.push_back({xk - b, yk - a});

    vector<pair<int, int>> queen; // pair<int,int> king= (x1,y1) ...
    queen.push_back({xq + a, yq + b});
    queen.push_back({xq + a, yq - b});
    queen.push_back({xq - a, yq + b});
    queen.push_back({xq - a, yq - b});
    queen.push_back({xq + b, yq + a});
    queen.push_back({xq + b, yq - a});
    queen.push_back({xq - b, yq + a});
    queen.push_back({xq - b, yq - a});

    // the problem is i'm recounting some the positions
    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (king[i].first == queen[j].first)
            {
                if (king[i].second == queen[j].second)
                {
                    ans++;
                }
            }
        }
    }
    // a more better soln is written in soln2.cpp
    cout << ans << endl;
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
        solve();
    }

    return 0;
}
