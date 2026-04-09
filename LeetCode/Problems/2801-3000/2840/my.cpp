#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tle
    bool checkStrings(string s1, string s2)
    {
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 2; j < n; j += 2)
            {
                if (s1[i] == s2[i])
                    break;
                else if (s1[j] == s2[i])
                {
                    swap(s1[i], s1[j]);
                    break;
                }
            }
        }
        return s1 == s2;
    }
};
// parity-based matching: even-index characters must match even-index characters, and odd-index characters must match odd-index characters.
// two pointers
bool checkStrings(string s1, string s2)
{
    int n = s1.size();
    int even1 = 0, even2 = 0;
    int odd1 = 1, odd2 = 1;

    while (even1 < n && even2 < n)
    {
        while (even1 < n && s1[even1] != s2[even2])
        {
            even1 += 2;
        }
        if (even1 == n)
        {
            return false;
        }

        while (odd1 < n && s1[odd1] != s2[odd2])
        {
            odd1 += 2;
        }
        if (odd1 == n)
        {
            return false;
        }

        swap(s1[even1], s1[even2]);
        swap(s1[odd1], s1[odd2]);

        even1 += 2;
        even2 += 2;
        odd1 += 2;
        odd2 += 2;
    }

    return s1 == s2;
}
int main()
{
}