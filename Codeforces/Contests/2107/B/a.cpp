#include <bits/stdc++.h>
using namespace std;

bool isvalid(vector<int> &arr, int n, int k)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        if (arr[i] > 0)
        {
            a++;
        }
        if (a == 0)
            return false;
    }
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    int ans = maxi - mini;
    return ans <= k;
}

int findmaxindex(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            index = i;
        }
    }
    return index;
}

void solve(int n, int k, vector<int> &a)
{
    // let tom=0; jerry=1;
    int flip = 0;
    do
    {
        int index = findmaxindex(a, n);
        if (a[index] > 0)
        {
            a[index]--;
        }
        flip++;
    } while (isvalid(a, n, k));

    if (flip == 0)
    {
        cout << "Tom\n";
    }
    else 
    if (flip % 2 == 0)
    {
        cout << "Tom\n";
    }
    else
    {
        cout << "Jerry\n";
    }
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
        int k;
        cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(n, k, a);
    }

    return 0;
}
