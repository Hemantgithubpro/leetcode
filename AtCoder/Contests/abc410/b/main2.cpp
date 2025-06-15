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

    int N, Q;
    cin >> N >> Q;
    
    vector<int> X(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> X[i];
    }

    vector<int> box_count(N + 1, 0);
    vector<int> result;

    for (int i = 0; i < Q; ++i) {
        int xi = X[i];
        if (xi >= 1) {
            box_count[xi]++;
            result.push_back(xi);
        } else {
            int min_count = box_count[1];
            int chosen_box = 1;
            for (int j = 2; j <= N; ++j) {
                if (box_count[j] < min_count) {
                    min_count = box_count[j];
                    chosen_box = j;
                }
            }
            box_count[chosen_box]++;
            result.push_back(chosen_box);
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;


    return 0;
}
