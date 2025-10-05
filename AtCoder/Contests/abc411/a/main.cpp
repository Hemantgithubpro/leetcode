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

    string s;
    cin >> s;
    int l;
    cin >> l;
    bool a = true;
    int b = s.size();
    for (int i = 0; i < b; i++)
    {
        if (s[i] < 97 || s[i] > 122)
            a = false;
    }
    if (b < l || a == false)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
