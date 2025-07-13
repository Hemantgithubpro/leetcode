#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to check if a string is palindrome
bool isPalindrome(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// Function to convert number to base-A string
string toBaseA(ll num, int a) {
    string res;
    while (num) {
        res += to_string(num % a);
        num /= a;
    }
    reverse(res.begin(), res.end());
    return res.empty() ? "0" : res;
}

// Generate palindromes by mirroring first half
void generatePalindromes(int len, string& half, ll& sum, int a, ll n) {
    if (half.size() * 2 > len) {
        // Generate palindrome
        string num = half;
        string rev = half;
        reverse(rev.begin(), rev.end());
        if (len % 2 == 1 && !half.empty()) {
            rev = rev.substr(1); // Remove first digit for odd length
        }
        num += rev;
        ll val = stoll(num);
        if (val <= n && val > 0) {
            if (isPalindrome(toBaseA(val, a))) {
                sum += val;
            }
        }
        return;
    }
    
    // Start with 1 for first digit to avoid leading zeros
    int start = (half.empty() ? 1 : 0);
    for (int d = start; d <= 9; d++) {
        half += to_string(d);
        generatePalindromes(len, half, sum, a, n);
        half.pop_back();
    }
}

int main() {
    int a;
    ll n;
    cin >> a >> n;
    
    ll sum = 0;
    // Handle single-digit numbers
    for (int i = 1; i <= min(9LL, n); i++) {
        string s = to_string(i);
        if (isPalindrome(toBaseA(i, a))) {
            sum += i;
        }
    }
    
    // Generate palindromes up to length of n
    int maxLen = to_string(n).size();
    string half;
    for (int len = 2; len <= maxLen; len++) {
        generatePalindromes(len, half, sum, a, n);
    }
    
    cout << sum << endl;
    return 0;
}