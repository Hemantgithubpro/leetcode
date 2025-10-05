#include <bits/stdc++.h>
using namespace std;

bool matchPattern(string &num, string &pattern)
{
    for (int i = 0; i < pattern.size(); i++)
    {
        if ((pattern[i] == 'I' && num[i] > num[i + 1]) || (pattern[i] == 'D' && num[i] < num[i + 1]))
            return false;
    }
    return true;
}

string smallestNumber(string pattern)
{
    // brute force approach is 9!, trying all combinations.
    // in cpp stl: next_permutation(num.begin())

    int n = pattern.size();
    string num = "";
    for (int i = 1; i <= n + 1; i++)
    {
        num.push_back(i + '0');
    }

    while (!matchPattern(num, pattern))
    {
        next_permutation(num.begin(), num.end());
    }
    return num;
}

int main()
{
    string pattern = "IIIDIDDD";
    cout << smallestNumber(pattern);
}