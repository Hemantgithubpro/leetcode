#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool valid = true;
        long long d = a[1] - a[0];
        for (int i = 2; i < n; i++) {
            if (a[i] != a[0] + static_cast<long long>(i) * d) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "NO\n";
        } else {
            long long numerator = 2LL * a[0] - a[1];
            if (numerator < 0) {
                cout << "NO\n";
            } else {
                long long total = n + 1LL;
                if (numerator % total != 0) {
                    cout << "NO\n";
                } else {
                    long long y = numerator / total;
                    long long x = d + y;
                    if (x >= 0) {
                        cout << "YES\n";
                    } else {
                        cout << "NO\n";
                    }
                }
            }
        }
    }

    return 0;
}