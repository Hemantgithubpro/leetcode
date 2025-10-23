#include <bits/stdc++.h>
using namespace std;

// did with recursion
class Solution
{
public:
    bool hasSameDigits(string s)
    {
        if (s.size() == 2)
            return s[0] == s[1];

        string temp = "";
        for (int i = 0; i < s.size() - 1; i++)
        {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            int c = (a + b) % 10;
            temp += c + '0';
        }
        return hasSameDigits(temp);
    }
};

int main()
{
}