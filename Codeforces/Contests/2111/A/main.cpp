#include <bits/stdc++.h>
using namespace std;

// time complexity of this algo will be log n (base 2).

bool valid(vector<int> &a)
{
    // a[i] >= a[j]/2   three combinations, 0,1     0,2     1,2
    if (a[0] < a[1] / 2)
        return false;
    if (a[0] < a[2] / 2)
        return false;
    if (a[1] < a[2] / 2)
        return false;
    return true;
}

vector<int> sol(vector<int> &a, int index)
{
    int mini = INT_MAX;
    if (index == 0)
    {
        // i = 1,2
        for (int i = 1; i <= 2; i++)
        {
            mini = min(a[i], mini);
        }
        a[0] = (mini * 2) + 1;
    }
    else if (index == 1)
    {
        mini = min(a[0], mini);
        mini = min(a[2], mini);
        a[1] = (mini * 2) + 1;
    }
    else
    {
        mini = min(a[0], mini);
        mini = min(a[1], mini);
        a[2] = (mini * 2) + 1;
    }
    return a;
}

bool checkifreachedx(vector<int> &a, int x)
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i] >= x)
            return true;
    }
    return false;
}

// this soln is brute force
void solve(int x)
{
    vector<int> a(3, 0);
    int ans = 0;
    int i = 0;
    cout<<checkifreachedx(a,x);
    while (!checkifreachedx(a, x))
    {
        a=sol(a,i%3);
        i++;
        ans++;
    }
    cout<<ans-1;
    cout << endl;
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
        int x;
        cin >> x;
        solve(x);
    }

    return 0;
}
