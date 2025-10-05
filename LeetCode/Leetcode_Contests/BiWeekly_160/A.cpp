#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toHex(long long num)
    {
        if (num == 0)
            return "0";

        string result = "";
        string chars = "0123456789ABCDEF";

        while (num > 0)
        {
            result += chars[num % 16];
            num /= 16;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string toBase36(long long num)
    {
        if (num == 0)
            return "0";

        string result = "";
        string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        while (num > 0)
        {
            result += chars[num % 36];
            num /= 36;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string toHexBase36(int n)
    {
        long long n2 = (long long)n * n;
        long long n3 = n2 * n;

        string hex = toHex(n2);
        string base36 = toBase36(n3);

        return hex + base36;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    cout << "n=13: " << sol.toHexBase36(13) << endl; // Expected: A91P1

    // Test case 2
    cout << "n=36: " << sol.toHexBase36(36) << endl; // Expected: 5101000

    return 0;
}