#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &arr)
{
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    int res1 = 0, res2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(arr[i]) > abs(arr[0]))
            res1++;
        else
            res2++;
    }
    if (res1 /= n / 2 || res2 == n / 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(n, arr);
    }

    return 0;
}
