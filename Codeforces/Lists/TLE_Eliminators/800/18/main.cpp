#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
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
        int k, x;
        cin >> x >> k;
        // we cannot jump multiples of k. i.e. k,2k,3k ...
        vector<int> ans;
        int temp = 0;
        for (int i = x; i > 0; i--)
        {
            // cout<<"i:"<<i<<" ";
            if (i % k != 0)
            {
                while (temp + i <= x)
                {
                    temp += i;
                    ans.push_back(i);
                }
            }
        }
        if(temp==x){
            cout<<ans.size()<<endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        // else if(temp<x){

        // }
    }

    return 0;
}
