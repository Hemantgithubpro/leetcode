#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int n = s.size();

    unordered_map<char, char> um;
    for (int i = 0; i < n; i++)
    {
        char temp = s[i];
        char temp2 = t[i];
        um[temp] = temp2;
    }
    for (int i = 0; i < n; i++)
    {
        char temp = s[i];
        char temp2 = t[i];
        if (um[temp] != temp2)
            return false;
    }

    unordered_map<char, char> um2;
    for (int i = 0; i < n; i++)
    {
        char temp2 = t[i];
        char temp = s[i];
        um2[temp2] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        char temp2 = t[i];
        char temp = s[i];
        if (um2[temp2] != temp)
            return false;
    }
    return true;
}

int main()
{
}