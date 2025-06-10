#include <bits/stdc++.h>
using namespace std;

void solve(){
    // code
}

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
        vector<int> a(n-1);
        long long sum=0;
        for (int i = 0; i < n-1; i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        cout<<-1*sum<<endl;
    }

    return 0;
}
