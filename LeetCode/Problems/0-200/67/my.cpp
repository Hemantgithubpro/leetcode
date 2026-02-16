#include <bits/stdc++.h>
using namespace std;

// string addBinary(string a, string b)
// {
//     // 101, 10: 111
//     // 1010, 1011: 10101
//     string ans = ""; // or add a on b
//     int r = max(a.size(), b.size());
//     int l = min(a.size(), b.size());
//     for(int i=r; i>=l; i--){

//     }
// }

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;

        // reverse a,b
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < max(a.length(), b.length()); i++)
        {
            int digitA = i < a.length() ? a[i] - '0' : 0;
            int digitB = i < b.length() ? b[i] - '0' : 0;

            int total = digitA + digitB + carry;
            string c = to_string(total % 2);
            ans = c + ans;
            carry = total / 2;
        }

        if (carry > 0)
            ans = "1" + ans;

        return ans;
    }
};

int main()
{
}