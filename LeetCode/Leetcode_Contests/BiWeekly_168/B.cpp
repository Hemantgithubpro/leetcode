#include <bits/stdc++.h>
using namespace std;

string maxSumOfSquares(int num, int sum)
{
    int drevantor = sum;
    
    // Check if it's possible to create such number
    // Minimum sum: all digits are 0 (but need at least one non-zero for num digits) = 1
    // Maximum sum: all digits are 9 = 9 * num
    if (sum < 1 || sum > 9 * num)
    {
        return "";
    }
    
    // To maximize sum of squares: use larger digits
    // To maximize the number itself: put larger digits at the beginning
    // Strategy: greedily place 9s from left to right
    
    string result(num, '0');
    int remaining = sum;
    
    for (int i = 0; i < num; i++)
    {
        // Put the largest digit possible at position i
        int digit = min(9, remaining);
        result[i] = '0' + digit;
        remaining -= digit;
    }
    
    return result;
}

int main()
{
    // Test cases
    cout << maxSumOfSquares(3, 15) << endl; // Expected: "960" or "699" etc
    cout << maxSumOfSquares(2, 10) << endl; // Expected: "91"
    cout << maxSumOfSquares(1, 10) << endl; // Expected: "" (impossible)
    cout << maxSumOfSquares(4, 1) << endl;  // Expected: "1000"
    
    return 0;
}