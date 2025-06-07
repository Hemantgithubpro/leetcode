#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int,int> um;
    for (int i = 0; i < n; i++)
    {
        um[a[i]]++;
    }

    int x=0;
    for (auto it = um.begin(); it!=um.end(); it++)
    {
        // cout << it->first << " " << it->second << endl;
        if(it->first <= it->second){
            x=max(x,it->first);
        }
    }
    cout<<x;
    
    

    return 0;
}
