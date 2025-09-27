#include <bits/stdc++.h>
using namespace std;

// i took the hint of reading from the back
int romanToInt(string s)
{
    unordered_map<char, int> um = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    if (s.size() == 1)
        return um[s[0]];

    int cnt = 0;
    for (int i = s.size() - 2; i >= 0; i--)
    {
        // char curr = s[i];
        // char prev = s[i - 1];
        // int c = um[curr];
        // int p = um[prev];
        // if (p < c)
        // {
        //     // IV
        //     cnt += c;
        //     cnt -= p;
        //     i--;
        // }
        // else
        // {
        //     // II
        //     cnt += c;
        // }
        char curr = s[i];
        char next = s[i + 1];
        int c = um[curr];
        int n = um[next];
        if (c < n)
            cnt -= c;
        else
            // II
            cnt += c;
    }
    int last = um[s[s.size() - 1]];
    int prev = um[s[s.size() - 2]];
    if (prev < last)
    {
        cnt -= 2 * prev;
        cnt += last;
    }
    else
        cnt += last;
    return cnt;
}

int main()
{
}