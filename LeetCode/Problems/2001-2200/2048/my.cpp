#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isbalanced(string s)
    {
        unordered_map<int, int> um;
        for (int i = 0; i < s.size(); i++)
        {
            int temp = s[i] - '0';
            um[temp]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            int temp = s[i] - '0';
            if (um[temp] != temp)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n)
    {
        for (int i = n + 1; i <= 1e6; i++)
        {
            string s = to_string(i);
            if (isbalanced(s))
                return i;
        }
        return -1;
    }
};

int main()
{
}