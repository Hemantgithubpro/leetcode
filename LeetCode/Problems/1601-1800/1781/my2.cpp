#include <bits/stdc++.h>
using namespace std;

// Optimized O(n^2) approach - no substring creation
int beautySum(string s)
{
    int ans = 0;
    int n = s.size();

    // For each starting position
    for (int i = 0; i < n; i++)
    {
        // Use array for frequency counting (faster than map for lowercase letters)
        int freq[26] = {0};

        // Expand the window by moving right pointer
        for (int j = i; j < n; j++)
        {
            // Add current character to frequency map
            freq[s[j] - 'a']++;

            // Calculate beauty for substring [i, j]
            if (j - i + 1 >= 2) // At least 2 characters needed
            {
                int maxFreq = 0, minFreq = INT_MAX;

                // Find max and min frequencies among characters present in substring
                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 0)
                    {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                ans += (maxFreq - minFreq);
            }
        }
    }

    return ans;
}

int main()
{
    string s = "aabcb";

    cout << beautySum(s) << endl;

    return 0;
}