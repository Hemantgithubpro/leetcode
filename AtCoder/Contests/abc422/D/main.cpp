#include <bits/stdc++.h>
using namespace std;
void distribute_ones(int l, int r, int ones, vector<int> &arr)
{
    if (ones == 0)
    {
        return;
    }
    if (l == r)
    {
        arr[l] += ones;
        return;
    }
    int total = r - l + 1;
    int left_size = total / 2;

    int left_ones = (int)(1LL * ones * left_size / total);

    int right_ones = ones - left_ones;
    int mid = l + left_size - 1;
    distribute_ones(l, mid, left_ones, arr);
    distribute_ones(mid + 1, r, right_ones, arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long K;
    cin >> N >> K;

    int L = 1 << N;
    int A = K / L;
    int R = K % L;

    vector<int> arr(L, A);
    if (R > 0)
    {
        distribute_ones(0, L - 1, R, arr);
    }

    int U = (R == 0) ? 0 : 1;

    cout << U << "\n";
    for (int i = 0; i < L; i++)
    {
        cout << (i == 0 ? "" : " ") << arr[i];
    }
    cout << "\n";

    return 0;
}