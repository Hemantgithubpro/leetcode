#include <bits/stdc++.h>
using namespace std;

int score(vector<string> &cards, char x)
{
    unordered_map<char, int> countfirst;  // x at position 0
    unordered_map<char, int> countsecond; // x at position 1
    int points = 0;
    for (const string &s : cards)
    {
        char a = s[0], b = s[1];
        if (a == x && b == x)
        {
            // skip, no card with both x can be paired (would need to differ by 1 character)
            continue;
        }
        else if (a == x)
        {
            countsecond[b]++; // store second character
        }
        else if (b == x)
        {
            countfirst[a]++; // store first character
        }
    }
    // Now, pair countfirst[c] and countsecond[c]
    for (char c = 'a'; c <= 'j'; ++c)
    {
        points += min(countfirst[c], countsecond[c]);
    }
    return points;
}

int main()
{
    vector<string> cards = {"aa", "ab", "ba", "ac"};
    char x = 'a';
    cout << score(cards, x);
    return 0;
}