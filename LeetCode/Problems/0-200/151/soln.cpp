// this solution is with two pointers

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    // remove leading spaces
    int start_i = 0;
    while (s[start_i] == ' ')
        start_i++;
    s = s.substr(start_i);
    reverse(s.begin(), s.end());
    // remove trailing spaces
    start_i = 0;
    while (s[start_i] == ' ')
        start_i++;
    s = s.substr(start_i);
    int n = s.size();
    int idx = 0; // idx that has the correct ans
    for (int l = 0; l < n; l++)
    {
        if (s[l] != ' ')
        {
            if (idx != 0)
            {
                s[idx] = ' ';
                idx++;
            }
            // find end of current word and move it to correct position
            int r = l;
            while (r < n && s[r] != ' ')
                s[idx++] = s[r++];
            // reverse [l, r]
            reverse(s.begin() + idx - (r - l), s.begin() + idx);
            l = r;
        }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
}

int main()
{
}