#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

long long power(int base, int exp)
{
    long long res = 1;
    for (int i = 0; i < exp; ++i)
    {
        res *= base;
    }
    return res;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;
    long long X;
    std::cin >> N >> K >> X;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> S[i];
    }

    // Sort the initial strings lexicographically.
    std::sort(S.begin(), S.end());

    // Convert X from 1-based to 0-based index.
    X--;

    std::string result_string = "";

    // Construct the result string component by component.
    for (int i = K; i > 0; --i)
    {
        // Calculate the size of the sub-problem space.
        long long block_size = power(N, i - 1);

        // Find the index of the current string component.
        int index = X / block_size;

        // Append the chosen string to the result.
        result_string += S[index];

        // Update X for the next smaller sub-problem.
        X %= block_size;
    }

    std::cout << result_string << std::endl;

    return 0;
}