#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> names(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> names[i];
    }

    int x;
    string y;
    cin >> x >> y;

    if (names[x] == y)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}