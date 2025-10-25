#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        // int32_t ans = 0;
        long long ans = 0;
        bool sign = true; // positive by default
        for (size_t i = 0; i < s.size(); i++)
        {
            if (isspace(s[i]))
                continue;
            if (i > 0)
            {
                if ((s[i] == '-' || s[i] == '+') && (s[i - 1] != ' '))
                    break;
            }
            if (s[i] == '-')
            {
                sign = false;
                continue;
            }
            if (s[i] == '.')
                break;
            if (isalpha(s[i]))
                break;
            if (isdigit(s[i]))
                ans = ans * 10 + (s[i] - '0');
            if (ans > (INT_MAX))
            {
                if (sign)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }
        ans = static_cast<int32_t>(ans);
        return sign ? ans : -ans;
    }
};