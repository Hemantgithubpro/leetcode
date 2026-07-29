// the suggestion from this, mine own solution: Replace iterative next_permutation with mathematical combinatorial counting to construct the k-th half-string directly.
// i can reduce tle by: skipping some no. of permutations like: if k>some_n, and abcd, with prefix 'a', only 3! permutations happen, so skip to 'b' prefix and so on.

#include <bits/stdc++.h>
using namespace std;

string kthpermutation(string a, int k)
{
    sort(a.begin(), a.end());
    k--;

    for (int i = 0; i < k; i++)
    {
        // next_permutation(a.begin(), a.end());
        if (!next_permutation(a.begin(), a.end())) {
            return "-1";
        }
    }
    return a;
}

string smallestPalindrome(string s, int k)
{
    int n = s.size();
    if (n % 2)
    {
        // leave the middle element
        string a = s.substr(0, n / 2);
        string b = kthpermutation(a, k);
        if(b=="-1") return "";
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
        if(b=="-1") return "";
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