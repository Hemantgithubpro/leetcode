// this potd is hard, but let's try.
#include <bits/stdc++.h>
using namespace std;
// From Hint, for base 10, check only for palindrome numbers.
// still tle, on k=7,n=30

string tokbase(long long a, int k)
{
    // you divide it by 'k', take the remainder and append it to answer.
    string ans = "";
    while (a > 0)
    {
        string temp;
        int rem = a % k;
        a = a / k;
        temp = to_string(rem);
        ans += temp;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool iskmirror(long long n, int k)
{
    string s = to_string(n);
    string temps = s;
    reverse(temps.begin(), temps.end());
    if (s != temps)
        return false;
    string d = tokbase(n, k);
    string d2 = d;
    reverse(d2.begin(), d2.end());
    if (d != d2)
        return false;
    return true;
}

vector<string> generateEvenPalindromearray(int digits)
{
    vector<string> palindromes;
    int start = pow(10, (digits - 1) / 2);
    int end = pow(10, digits / 2);

    for (int i = start; i < end; ++i)
    {
        string s = to_string(i);
        string rev = s;
        reverse(rev.begin(), rev.end());
        palindromes.push_back(s + rev);
    }

    return palindromes;
}

vector<string> generateOddPalindromearray(int digits)
{
    digits--;
    // Generates palindromes with odd number of digits
    // For example, for digits = 3, it generates palindromes like 101, 111, 121, etc.
    vector<string> palindromes;
    int start = pow(10, (digits - 1) / 2);
    int end = pow(10, (digits + 1) / 2);
    for (int i = start; i < end; ++i)
    {
        string s = to_string(i);
        string rev = s;
        reverse(rev.begin(), rev.end());
        // Generate palindromes like 101, 111, 121, etc.
        for (char c = '0'; c <= '9'; ++c)
        {
            palindromes.push_back(s + c + rev);
        }
    }

    return palindromes;
}

vector<string> generatePalindromearray(int digits)
{
    if (digits <= 0)
        return {};
    if (digits % 2 == 0)
    {
        // even number of digits
        return generateEvenPalindromearray(digits);
    }
    else
    {
        // odd number of digits
        return generateOddPalindromearray(digits);
    }
}

long long kMirror(int k, int n)
{
    // sum of the 'n' smallest k-mirrored numbers
    // brute force soln
    long long ans = 0;
    int count = 0;
    bool found = false;

    for (long long i = 1; i < 10; i++)
    {

        if (iskmirror(i, k))
        {
            ans += i;
            count++;
            if (count >= n)
            {
                found = true;
                break;
            }
        }
    }

    for (long long i = 2; !found; i++)
    {
        vector<string> palindromes = generatePalindromearray(i);
        // for each number, generate palindromes of that length
        for (const string &palindrome : palindromes)
        {
            long long num = stoll(palindrome);
            if (iskmirror(num, k))
            {
                ans += num;
                count++;
                if (count >= n)
                {
                    found = true;
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    int n = 17;
    int k = 7;
    // cout << iskmirror(k, n);
    cout << kMirror(k, n);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\nTime taken: " << duration.count() << " milliseconds" << endl;
}