#include <bits/stdc++.h>
using namespace std;

// such a basic question bcoz of silly constraints, constraints were 10^4, if it had been 10^18, then algorithm would be tricky
int noofdigits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n /= 10;
        ans++;
    }
    return ans;
}
int countSymmetricIntegers(int low, int high)
{
    int ans = 0;
    for (int i = low; i <= high; i++)
    {
        if (noofdigits(i) % 2 == 0)
        {
            int digits = noofdigits(i);
            int initial = 0, last = 0;
            int temp = digits;
            int tempi = i;
            while (temp > digits / 2)
            {
                last += (tempi % 10);
                tempi /= 10;
                temp--;
            }
            while (temp > 0)
            {
                initial += (tempi % 10);
                tempi /= 10;
                temp--;
            }
            if (initial == last)
                ans++;
        }
    }
    return ans;
}

int main()
{
}