// without unordered map

// this will be n^2

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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    
    for(int i=0; i<n; i++){
        if(a[i]<= i+1){
            cout<<a[i];
            return 0;
        }
    }
    // cout << x;

    return 0;
}
