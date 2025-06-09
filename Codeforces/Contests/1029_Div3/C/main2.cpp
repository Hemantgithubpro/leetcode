#include <iostream>
#include <vector>
using namespace std;

bool ifallequal(vector<int>&arr){
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[0]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // this if funcn was stopping the soln
        if(ifallequal(a)){
            cout<<n<<endl;
            continue;
        }
        vector<int> last_occurrence_in_segment(n + 1, -1);
        int l = 0, r = n - 1;
        int segments = 0;

        while (l <= r) {
            vector<int> distinct;
            for (int i = r; i >= l; i--) {
                if (last_occurrence_in_segment[a[i]] == -1) {
                    last_occurrence_in_segment[a[i]] = i;
                    distinct.push_back(a[i]);
                }
            }
            if (distinct.empty()) {
                segments++;
                break;
            }
            int min_last = r;
            for (int x : distinct) {
                if (last_occurrence_in_segment[x] < min_last) {
                    min_last = last_occurrence_in_segment[x];
                }
            }
            for (int x : distinct) {
                last_occurrence_in_segment[x] = -1;
            }
            segments++;
            r = min_last - 1;
        }
        cout << segments << '\n';
    }
    return 0;
}