#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int n = s.size();
    // int32_t ans = 0;
    long long ans = 0;
    bool sign = true; // positive by default
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
            continue;
        if (s[i] == '-')
            sign = false;
        if (isalpha(s[i]))
            break;
        if (i > 0)
        {
            if ((s[i] == '-' || s[i] == '+') && (s[i - 1] != ' '))
                break;
        }

        int temp = s[i] - '0';
        ans += temp;
        if (i != n - 1 || !isalpha(s[i+1]) )
            ans *= 10;
        if (ans > (INT_MAX))
        {
            ans = INT_MAX;
            break;
        }
    }
    if (!sign)
        ans *= -1;
    int a = static_cast<int>(ans);
    return a;
}

int main()
{
    string s = "34";
    cout << myAtoi(s);
}