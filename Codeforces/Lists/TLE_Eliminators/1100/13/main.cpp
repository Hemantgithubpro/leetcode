#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void solve(){
    int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end()); 

	vector<int> b(n);
	for (int i = 0; i < n; i++) { 
		cin >> b[i];
	}

	sort(b.rbegin(), b.rend());

	ll result = 1;

	for (int i = 0; i < n; i++) { 
		// Find the number of elements in a that are greater than b[i]
		ll temp = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
		ll count = a.size() - temp;

		// Update the result with the number of valid positions for a[i]
		result = result * max(count - i, 0LL) % mod;
	}

	cout << result << endl;

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        // ll n;
        // cin>>n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin>>a[i];
        // }
        // solve(n,a);
        
        solve();
    }

    return 0;
}
