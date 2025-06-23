#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        bool alreadyBeautiful = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(a[i] - a[i + 1]) <= 1)
            {
                alreadyBeautiful = true;
                break;
            }
        }

        if (alreadyBeautiful)
        {
            cout << 0 << endl;
        }
        else if (n <= 2)
        {
            // Only one pair, and it's not beautiful
            cout << -1 << endl;
        }
        else if (n == 3)
        {
            
        }
        else {
            cout<<1<<endl;
        }
    }
    return 0;
}
