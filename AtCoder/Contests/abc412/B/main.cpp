#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string S, T;
    cin >> S >> T;

    for (int i = 1; i < S.length(); i++)
    {
        if (S[i] >= 'A' && S[i] <= 'Z')
        {
            if (T.find(S[i - 1]) == string::npos)
            {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
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

    // input
    solve();

    return 0;
}
