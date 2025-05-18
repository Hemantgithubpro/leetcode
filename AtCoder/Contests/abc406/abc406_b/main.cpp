#include <bits/stdc++.h>
using namespace std;

int finddigits(long long a)
{
    // if(a==0) return 0;
    int i = 0;
    while (a >= 1)
    {
        a = a / 10;
        i++;
    }
    return i;
}

void solve(int n, int k, vector<int> &arr)
{
    long long mul = 1;
    for (int i = 0; i < n; i++)
    {
        mul = mul * arr[i];
        if (finddigits(mul) > k)
            mul = 1;
    }
    cout << mul;
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(n, k, arr);

    return 0;
}
