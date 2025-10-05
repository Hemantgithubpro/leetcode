#include <bits/stdc++.h>
using namespace std;

// Wrong answer on test 2	everytime
// i missed out on the case, what if the last were opened doors also.
void solve(int n, int x, vector<int> &arr)
{
    // open doors=0
    // closed door=1
    int firstoccurofcloseddoor = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            firstoccurofcloseddoor = i;
            break;
        }
    }
    if (firstoccurofcloseddoor == -1)
    {
        cout << "YES" << endl;
        return;
    }

    int finalplace = firstoccurofcloseddoor + x;
    for (int i = finalplace; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

    // int rest = n - 1 - firstoccurofcloseddoor;
    // if (rest <= x)
    // {
    //     cout << "YES" << endl;
    // }
    // else
    //     cout << "NO" << endl;
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
        int n;
        cin >> n;
        int x;
        cin >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(n, x, a);
    }

    return 0;
}
