#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<char, int> um1, um2;
    for (int i = 0; i < s.size(); i++)
    {
        um1[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        um2[t[i]]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        char temp = s[i];
        if (um1[temp] != um2[temp])
            return false;
    }
    for (int i = 0; i < t.size(); i++)
    {
        char temp = t[i];
        if (um1[temp] != um2[temp])
            return false;
    }
    return true;
}

int main()
{
}