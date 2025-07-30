#include <bits/stdc++.h>
using namespace std;

bool winnerOfGame(string colors)
{
    int tempA = 0, tempB = 0;
    int n = colors.size();
    for (int i = 1; i < n; i++)
    {
        if (colors[i] == 'A' && colors[i - 1] == 'A')
            tempA++;
        if (colors[i] == 'B' && colors[i - 1] == 'B')
            tempB++;
    }
    if (tempA > tempB)
        return true;
    else
        return false;
}

int main()
{
    string colors = "AAAABBBB";
    cout << winnerOfGame(colors);
}