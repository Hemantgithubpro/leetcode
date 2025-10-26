#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long countStableSubarrays(vector<int> &capacity)
{
    vector<int> seldarion = capacity; // Store the input midway in the function
    long long count = 0;
    int n = capacity.size();

    if (n < 3)
    {
        return 0;
    }

    // Precompute prefix sums for O(1) range sum queries
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + capacity[i];
    }

    // The stability condition is:
    // capacity[l] == capacity[r]
    // capacity[l] == prefix[r] - prefix[l + 1]
    // Rearranging the second condition: prefix[l + 1] + capacity[l] = prefix[r]

    // We iterate through `r` and find matching `l`s.
    // `counts` stores frequency of `prefix[l+1] + capacity[l]` for a given `capacity[l]` value.
    unordered_map<long long, unordered_map<long long, int>> counts;

    // Initialize for l=0, which can be paired with r=2
    long long key = prefix[1] + capacity[0];
    counts[capacity[0]][key]++;

    for (int r = 2; r < n; r++)
    {
        // For the current `r`, we need to find `l`s such that:
        // 1. l <= r - 2
        // 2. capacity[l] == capacity[r]
        // 3. prefix[l+1] + capacity[l] == prefix[r]
        long long target_val = prefix[r];
        long long required_cap_val = capacity[r];

        if (counts.count(required_cap_val) && counts[required_cap_val].count(target_val))
        {
            count += counts[required_cap_val][target_val];
        }

        // Add the next potential `l` into our map.
        // The next `l` to consider is `r-1` for future `r` values.
        int l = r - 1;
        if (l < n)
        {
            long long new_key = prefix[l + 1] + capacity[l];
            counts[capacity[l]][new_key]++;
        }
    }

    return count;
}

int main()
{
    // Test case 1: [9,3,3,3,9]
    vector<int> test1 = {9, 3, 3, 3, 9};
    cout << "Test 1: " << countStableSubarrays(test1) << " (expected: 2)" << endl;
    
    // Test case 2: [1,2,3,4,5]
    vector<int> test2 = {1, 2, 3, 4, 5};
    cout << "Test 2: " << countStableSubarrays(test2) << " (expected: 0)" << endl;
    
    // Test case 3: [-4,4,0,0,-8,-4]
    vector<int> test3 = {-4, 4, 0, 0, -8, -4};
    cout << "Test 3: " << countStableSubarrays(test3) << " (expected: 1)" << endl;
    
    return 0;
}