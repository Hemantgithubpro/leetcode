#include <bits/stdc++.h>
using namespace std;
vector<int> splitInteger(int n, int k)
{
    vector<int> result(k, 1);

    // Factorize n and distribute factors to minimize differences
    for (int p = 2; p * p <= n; ++p)
    {
        while (n % p == 0)
        {
            // Find the smallest integer in result
            int min_idx = min_element(result.begin(), result.end()) - result.begin();
            result[min_idx] *= p;
            n /= p;
        }
    }

    // If n is a prime number > 1
    if (n > 1)
    {
        int min_idx = min_element(result.begin(), result.end()) - result.begin();
        result[min_idx] *= n;
    }

    return result;
}
int main()
{
    int k = 3, n = 44;
    vector<int> a = splitInteger(n, k);
    for (int num : a)
        cout << num << ' ';
}