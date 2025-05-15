#include <bits/stdc++.h>
using namespace std;

// funcn to give the index of the minimum element.
int findmin(vector<int> &arr)
{
    int mini = INT_MAX;
    int index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < mini)
        {
            mini=arr[i];
            index = i;
        }
    }
    return index;
}

void solve(vector<int> &jud)
{
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < jud.size(); i++)
    {
        sum += jud[i];
    }
    if (sum >= 35)
    cout << 0 << endl;
    else
    {
        int rem = 35 - sum;
        while (sum < 35)
        {
            int minindex=findmin(jud);
            int mini = jud[minindex];
            sum -= mini;
            sum += 10;
            jud[minindex] = 10;
            ans++;
        }
        cout << ans * 100 << endl;
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
        vector<int> jud(5);
        for (int i = 0; i < 5; i++)
        {
            cin >> jud[i];
        }
        solve(jud);
    }

    return 0;
}