#include <bits/stdc++.h>
using namespace std;

bool isvowel(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return true;
    return false;
}
bool doesAliceWin(string s)
{
    int noofvowels = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
        if (isvowel(s[i]))
            noofvowels++;
    if (noofvowels == 0)
        return false;
    return true;
}

int main()
{
}