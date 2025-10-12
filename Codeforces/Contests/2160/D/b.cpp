#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// A helper function to perform a query and read the result.
int ask(int i, int j)
{
    std::cout << "? 2 " << i << " " << j << std::endl;
    int result;
    std::cin >> result;
    if (result == -1)
    {
        exit(0); // Exit immediately if the judge returns an error.
    }
    return result;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> ans(2 * n + 1, 0);
    std::vector<int> unpaired_indices(2 * n);
    std::iota(unpaired_indices.begin(), unpaired_indices.end(), 1);

    // Loop until all indices are paired.
    while (!unpaired_indices.empty())
    {
        // If only one element is left, it must have been paired previously.
        // This case handles the final state.
        if (unpaired_indices.size() == 1)
        {
            break;
        }

        // Deterministic shuffle: split into odd and even positioned elements.
        std::vector<int> odds, evens;
        for (size_t i = 0; i < unpaired_indices.size(); ++i)
        {
            if (i % 2 == 0)
            {
                odds.push_back(unpaired_indices[i]);
            }
            else
            {
                evens.push_back(unpaired_indices[i]);
            }
        }

        // The list for the next round will contain indices that don't get paired.
        unpaired_indices.clear();

        // Process the list of elements from odd positions.
        for (size_t i = 0; i + 1 < odds.size(); i += 2)
        {
            int u = odds[i];
            int v = odds[i + 1];
            int mad = ask(u, v);
            if (mad > 0)
            {
                ans[u] = mad;
                ans[v] = mad;
            }
            else
            {
                unpaired_indices.push_back(u);
                unpaired_indices.push_back(v);
            }
        }
        // If there's a leftover element, it remains unpaired.
        if (odds.size() % 2 != 0)
        {
            unpaired_indices.push_back(odds.back());
        }

        // Process the list of elements from even positions.
        for (size_t i = 0; i + 1 < evens.size(); i += 2)
        {
            int u = evens[i];
            int v = evens[i + 1];
            int mad = ask(u, v);
            if (mad > 0)
            {
                ans[u] = mad;
                ans[v] = mad;
            }
            else
            {
                unpaired_indices.push_back(u);
                unpaired_indices.push_back(v);
            }
        }
        // If there's a leftover element, it remains unpaired.
        if (evens.size() % 2 != 0)
        {
            unpaired_indices.push_back(evens.back());
        }
    }

    // Output the final answer.
    std::cout << "!";
    for (int i = 1; i <= 2 * n; ++i)
    {
        std::cout << " " << ans[i];
    }
    std::cout << std::endl;
}

int main()
{
// Fast I/O
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}