#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

string converttoBaseK(long long n, int k)
{
    if (n == 0)
        return "0";
    string result = "";
    while (n > 0)
    {
        result += to_string(n % k);
        n /= k;
    }
    reverse(result.begin(), result.end());
    return result;
}

long long kMirror(int k, int n)
{
    long long sum = 0;
    int L = 1; // create L length palindromes
    while (n > 0)
    {
        int half_length = (L + 1) / 2;
        long long min_num = pow(10, half_length - 1);
        long long max_num = pow(10, half_length) - 1;
        for (int num = min_num; num <= max_num; num++)
        {
            string first_half = to_string(num);
            string second_half = first_half;
            reverse(begin(second_half), end(second_half));
            string pal = "";
            if (L % 2 == 0)
            { // even length palindrome
                pal = first_half + second_half;
            }
            else
            {
                pal = first_half + second_half.substr(1);
            }

            long long palindrome = stoll(pal);

            string base_k = converttoBaseK(palindrome, k);

            if (isPalindrome(base_k))
            {
                sum += palindrome;
                n--;
                if (n == 0)
                {
                    break;
                }
            }
        }
        L++;
    }
    return sum;
}