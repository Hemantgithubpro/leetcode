#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int n;
    cin >> n;
    string t;
    cin >> t;
    string a;
    cin >> a;

    bool q = false;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 'o' && a[i] == 'o')
        {
            q = true;
            break;
        }
    }
    if (q)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
