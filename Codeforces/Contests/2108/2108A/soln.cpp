#include <bits/stdc++.h>
using namespace std;

int solve(int &n)
{
    int x = n / 2;
    int sum = x * (2 * n - 2 - (x - 1) * 2); // x into 2n-2-2(x-1)
    int ans = (sum / 2) + 1;
    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}