#include <bits/stdc++.h>
using namespace std;

// unsigned long long fact(int n)
// {
//     static vector<unsigned long long> f = []()
//     {
//         vector<unsigned long long> v(21, 1);
//         for (int i = 1; i <= 20; i++)
//             v[i] = v[i - 1] * i;
//         return v;
//     }();
//     if (n > 20)
//         return ULLONG_MAX; // Overflow safeguard
//     return f[n];
// }

// Simple factorial function
int fact(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

// unsigned long long countUniquePermutations(const map<char, int>& freq) {
//     int total_chars = 0;
//     for (auto const& [ch, count] : freq) {
//         total_chars += count;
//     }
//     if (total_chars == 0) return 1;
//     unsigned long long total = fact(total_chars);
//     for (auto const& [ch, count] : freq) {
//         total /= fact(count);
//     }
//     return total;
// }

// Counts unique permutations from a frequency array of 26 letters:
// Formula: total! / (count1! * count2! * ...)
int countPermutations(int freq[])
{
    int total = 0;
    for (int i = 0; i < 26; i++)
    {
        total += freq[i];
    }
    if (total == 0)
        return 1;

    int ans = fact(total);
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 1)
        {
            ans /= fact(freq[i]);
        }
    }
    return ans;
}

string kthpermutation(string a, int k)
{
    int n = a.size();
    // Frequency array for 'a' through 'z'
    int freq[26] = {0};
    for (int i = 0; i < n; i++)
        freq[a[i] - 'a']++;

    // Check if k is out of bounds
    int total_perms = countPermutations(freq);
    if (k > total_perms)
        return "-1";

    string result = "";

    // Build the string position by position
    for (int i = 0; i < n; i++)
    {
        // Try each character 'a' through 'z' in alphabetical order
        for (int c = 0; c < 26; c++)
        {
            if (freq[c] == 0)
                continue;

            // Pick this character
            freq[c]--;

            // How many permutations can we form with the rest?
            int count = countPermutations(freq);

            if (k <= count)
            {
                // The k-th permutation starts with character 'a' + c
                result += (char)('a' + c);
                break; // move to next position
            }
            else
            {
                // Skip all permutations that start with this character
                k -= count;
                freq[c]++; // put it back to try the next character
            }
        }
    }

    return result;
}

string smallestPalindrome(string s, int k)
{
    int n = s.size();
    if (n % 2)
    {
        // leave the middle element
        string a = s.substr(0, n / 2);
        string b = kthpermutation(a, k);
        if (b == "-1")
            return "";
        string ans = b;
        ans += s[n / 2];
        reverse(b.begin(), b.end());
        ans += b;
        return ans;
    }
    else
    {
        string a = s.substr(0, n / 2);
        string b = kthpermutation(a, k);
        if (b == "-1")
            return "";
        string ans = b;
        reverse(b.begin(), b.end());
        ans += b;
        return ans;
    }
}

int main()
{
    string s = "abba";
    int k = 2;

    cout << smallestPalindrome(s, k);
    // cout<<kthpermutation("afa",2);
    return 0;
}