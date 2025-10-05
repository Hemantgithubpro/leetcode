#include <bits/stdc++.h>
using namespace std;
// this was the easiest as you just had to see if the element, k is present in the array or not.

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k; cin>>k;
        vector<int> a(n);
        unordered_set<int> us;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            us.insert(a[i]);
        }
        if(us.find(k)!=us.end()) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}
