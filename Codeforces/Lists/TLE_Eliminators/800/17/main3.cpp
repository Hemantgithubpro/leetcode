#include <bits/stdc++.h>
using namespace std;

bool isamultiple(int k, int n, int x){
    for(int i=2; i<=k; i++){
        if(i!=x){
            if(n%i==0){
                return true;
            }
        }
    }
    return false;
}

void solve(int n, int k, int x)
{
    if (x == k)
        k--;
    if (k == 0)
    {
        cout << "NO" << endl;
        return;
    }
    
    int temp=0;
    vector<int> ans;
    for (int i = k; i > 0; i--)
    {
        if(i!=x){

            // cout << "i: " << i << "  ";
            while (temp+i<=n)
            {
                // cout << "temp: " << temp << "  ";
                temp+= i;
                ans.push_back(i);
            }
        }
    }

    if (temp==n)
    {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
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
        // input
        int n, k, x;
        cin >> n >> k >> x;

        solve(n, k, x);
    }

    return 0;
}
