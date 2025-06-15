#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    // Initialize array A where A[i] = i+1 (1-indexed)
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        A[i] = i + 1;
    }

    // Track the rotation offset
    long long offset = 0;

    for (int q = 0; q < Q; q++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            // Type 1: Change A[p] to x
            int p, x;
            cin >> p >> x;
            p--; // Convert to 0-indexed

            // Calculate the actual position in the rotated array
            int actual_pos = (p + offset) % N;
            A[actual_pos] = x;
        }
        else if (type == 2)
        {
            // Type 2: Output A[p]
            int p;
            cin >> p;
            p--; // Convert to 0-indexed

            // Calculate the actual position in the rotated array
            int actual_pos = (p + offset) % N;
            cout << A[actual_pos] << "\n";
        }
        else if (type == 3)
        {
            // Type 3: Rotate left by k positions
            long long k;
            cin >> k;

            // Update offset (rotating left by k is equivalent to
            // moving the start position right by k)
            offset = (offset + k) % N;
        }
    }

    return 0;
}
