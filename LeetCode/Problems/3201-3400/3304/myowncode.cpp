#include <bits/stdc++.h>
using namespace std;

char kthCharacter(int k)
{
    // brute force
    string s = "a";
    while (s.size() < k)
    {
        string temp = s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != 'z')
            {
                temp += s[i] + 1;
            }
            else
            {
                temp += 'a';
            }
        }
        s = temp;
    }
    return s[k - 1];
}