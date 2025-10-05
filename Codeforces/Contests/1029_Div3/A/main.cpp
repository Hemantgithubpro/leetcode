#include <bits/stdc++.h>
using namespace std;

void solve(int n, int x, vector<int> &arr)
{
    // open doors=0
    // closed door=1
    // i'm missing out on edge cases
    int firstoccurofcloseddoor = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            firstoccurofcloseddoor = i;
            break;
        }
    }
    if(firstoccurofcloseddoor==-1){
        cout<<"YES"<<endl;
        return;
    }
    int rest=n-1;
    if(rest<=firstoccurofcloseddoor+x){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
