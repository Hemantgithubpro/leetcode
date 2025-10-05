// can use codechef.com/ide
#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int testcases;
    cin >> testcases;
    int ans = 0;
    while (testcases--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < 3; i++)
        {
            if (s[i] == '+')
            {
                ans++;
                break;
            }
            else if (s[i] == '-')
            {
                ans--;
                break;
            }
        }
    }
    cout << ans;
}