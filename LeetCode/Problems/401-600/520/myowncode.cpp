// did it in first attempt, not really a good question as i did not learn anything new
#include <bits/stdc++.h>
using namespace std;
bool detectCapitalUse(string word)
{
    // bool ans = true;
    // if the first letter is capital
    if (word.size() == 0)
        return true;
    if (word[0] < 91 && word[0] >= 65)
    {
        // if second letter is also capital
        if (word[1] < 91 && word[1] >= 65)
        {
            for (int i = 2; i < word.size(); i++)
            {
                if (word[i] >= 97)
                    return false;
            }
        }
        // if second letter is small
        else
        {
            for (int i = 2; i < word.size(); i++)
            {
                if (word[i] < 97)
                    return false;
            }
        }
    }
    // if first letter is small
    else if (word[0] >= 97 && word[0] < 123)
    {
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] < 97)
                return false;
        }
    }

    return true;
}

int main()
{
    string word;
    cin >> word;
    cout << detectCapitalUse(word) << endl;
    return 0;
}
// Time complexity: O(n), where n is the length of the word