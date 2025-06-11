#include <bits/stdc++.h>
using namespace std;

bool isgood(vector<int> &a)
{
    unordered_map<int, int> um;
    for (int i = 0; i < a.size(); i++)
    {
        um[a[i]]++;
    }
    if (um[-1] % 2 != 0)
        return false;
    if (um[1] - um[-1] < 0)
        return false;
    return true;
}

void solve(int n, vector<int>&a)
{
    // code
    int ans=0;
    if(isgood(a)){
        cout<<0<<endl;
        return;
    }
    
    int noofneg1=0;
    int noof1=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==1) noof1++;
        else noofneg1++;
    }
    while(noofneg1>noof1 && noofneg1>0){
        ans++;
        noofneg1--;
        noof1++;      
    }
    if(noofneg1%2!=0) ans++;
    cout<<ans<<endl;
    
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
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(n,a);
    }

    return 0;
}
