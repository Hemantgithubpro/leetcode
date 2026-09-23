#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &A, int x)
{
    int k = reduce(A.begin(), A.end()) - x, n = A.size();
    if (k < 0)
        return -1;
    if (k == 0)
        return n;

    int best = -1, i = 0, sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += A[j];
        while (sum > k)
            sum -= A[i++];

        if (sum == k)
            best = max(best, j - i + 1);
    }

    return best + 1 ? n - best : -1;
}

int main()
{
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    cout << minOperations(nums, x) << endl;
    return 0;
}