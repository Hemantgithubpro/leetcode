#include <bits/stdc++.h>
using namespace std;

int fewestballs(vector<int> &a)
{
    int min = a[0];
    int pos = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    int arr[q];
    vector<int> balls(n, 0);

    vector<int> ans(q, 0);
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++)
    {
        if (arr[i] == 0)
        {
            int pos=fewestballs(balls);
            balls[pos]++;
            ans[i] = 1;
        }
        else
        {
            ans[i] = i - 1;
        }
    }

    return 0;
}
