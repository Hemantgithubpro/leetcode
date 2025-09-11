#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// Function to solve a single test case
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Create a sorted version of the string to check if it's already sorted
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());

    // Case 0: The string is already sorted
    if (s == sorted_s) {
        cout << 0 << endl;
        return;
    }

    // Find the boundaries of the unsorted core
    int first_one = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            first_one = i;
            break;
        }
    }

    int last_zero = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            last_zero = i;
            break;
        }
    }

    // This case should be covered by the initial sorted check, but it's good practice
    if (first_one == -1 || last_zero == -1 || first_one > last_zero) {
        cout << 0 << endl;
        return;
    }
    
    // Check for the "hard" case requiring 2 operations
    bool has_stuck_ones = false;
    for (int i = first_one; i + 1 < n; ++i) {
        if (s[i] == '1' && s[i+1] == '1') {
            has_stuck_ones = true;
            break;
        }
    }

    bool has_stuck_zeros = false;
    for (int i = last_zero; i - 1 >= 0; --i) {
        if (s[i] == '0' && s[i-1] == '0') {
            has_stuck_zeros = true;
            break;
        }
    }
    
    // Case 2: Both stuck '11' and '00' patterns exist in the relevant parts
    if (has_stuck_ones && has_stuck_zeros) {
        cout << 2 << endl;
    } else {
        // Case 1: All other unsorted strings
        cout << 1 << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}