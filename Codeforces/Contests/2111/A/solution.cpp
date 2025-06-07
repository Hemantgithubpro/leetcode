// this is the solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        // it has taken three independent int, instead of a vector.
        int a = 0, b = 0, c = 0;
        int ans = 0;
        while (a < x)
        {
            a = min(x, 2 * b + 1);
            swap(a, b);
            swap(b, c);
            ans += 1;
        }
        cout << ans << '\n';
    }
    return 0;
}