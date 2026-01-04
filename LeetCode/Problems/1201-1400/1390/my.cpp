#include <bits/stdc++.h>
using namespace std;

int sumFourDivisors(vector<int> &nums)
{
    // 1 2 3 4 5 6
    // brute force: check divisors of all num in nums, and if divisors are 4, add their sum to result
    int result = 0;
    for (int n : nums)
    {
        int sum = 0;
        int numofdivisors = 0; // n itself is a divisor
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                numofdivisors++;
                sum += i;
                if (i != n / i)
                {
                    numofdivisors++;
                    sum += n / i;
                }
            }
        }
        if (numofdivisors == 4)
            result += sum;
    }
    return result;
}

int main()
{
    vector<int> nums = {21, 7, 4};
    cout << sumFourDivisors(nums);
    return 0;
}