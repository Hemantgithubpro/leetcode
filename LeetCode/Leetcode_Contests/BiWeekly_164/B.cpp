#include <bits/stdc++.h>
using namespace std;

int score(vector<string> &cards, char x)
{
    int points = 0;
    int none = 0;   // cards with no x
    int first = 0;  // cards where only first position is x
    int second = 0; // cards where only second position is x
    int both = 0;   // cards where both positions are x

    for (int i = 0; i < cards.size(); i++)
    {
        string s = cards[i];
        char a = s[0];
        char b = s[1];
        if (a == x && b == x)
            both++;
        else if (a == x)
            first++;
        else if (b == x)
            second++;
        else
            none++;
    }

    // Compatible pairs:
    // 1. none + first (differ in first position)
    int pair1 = min(none, first);
    points += pair1;
    none -= pair1;
    first -= pair1;

    // 2. none + second (differ in second position)
    int pair2 = min(none, second);
    points += pair2;
    none -= pair2;
    second -= pair2;

    // 3. first + both (differ in second position)
    int pair3 = min(first, both);
    points += pair3;
    first -= pair3;
    both -= pair3;

    // 4. second + both (differ in first position)
    int pair4 = min(second, both);
    points += pair4;

    return points;
}

// int score(vector<string> &cards, char x)
// {
//     int points = 0;
//     // count no. of cards containing char x
//     int count = 0; // count of cards with just one x
//     int doublecount = 0;
//     for (int i = 0; i < cards.size(); i++)
//     {
//         string s = cards[i];
//         char a = s[0];
//         char b = s[1];
//         if (a == x && b == x)
//             doublecount++;
//         else if (a == x || b == x)
//             count++;
//     }

//     // greedy approach: first match 1 doublecount and 1 count, or n doublecount and n count
//     int md = min(doublecount, count);
//     points += md;
//     doublecount -= points;
//     count -= points;

//     // now can't touch doublecount
//     points += count / 2;
//     return points;
// }

int main()
{
    vector<string> cards = {"aa", "ab", "ba", "ac"};
    char x = 'a';
    cout << score(cards, x);
    return 0;
}