#include <bits/stdc++.h>
using namespace std;

// it only generates size double of n's size
string generatePalindrome(int n)
{
    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s + rev;
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

int main()
{
    // cout << stoi(generatePalindrome(12));
    // vector<string> palindromes = generateEvenPalindromearray(4);
    auto start = chrono::high_resolution_clock::now();
    vector<string> palindromes = generateOddPalindromearray(1);
    for (const string &palindrome : palindromes)
    {
        cout << palindrome << " ";
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\nTime taken: " << duration.count() << " milliseconds" << endl;
    return 0;
}