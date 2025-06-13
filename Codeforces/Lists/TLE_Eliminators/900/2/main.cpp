#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    unordered_map<char, int> frq;
    for (int i = 0; i < s.size(); i++)
    {
        frq[s[i]]++;
    }

    // to find characters with frequency odd
    int count = 0;
    // while(count<=k){

    // }

    for (auto it = frq.begin(); it != frq.end(); it++)
    {
        if (it->second % 2 == 1)
            count++;
        it->second--;
    }
    if (n - k == 1)
        cout << "YES" << endl;
    else if (count == k)
        cout << "YES" << endl;
    else if (count < k)
    {
        int remaining = k - count;
        if (remaining % 2 == 1)
            cout << "NO" << endl;
        else
        {
            for (auto it = frq.begin(); it != frq.end(); it++)
            {
                if (it->second <= remaining){

                    remaining -= it->second;
                    it->second -= remaining;
                }
            }
            if(remaining==0) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
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
        solve();
    }

    return 0;
}
