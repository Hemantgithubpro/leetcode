#include <bits/stdc++.h>
using namespace std;

bool isValid(string word)
{
    bool vowel = false, consonant = false;
    if (word.size() < 3)
        return false;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] < 48)
            return false;
        else if (word[i] > 57)
        {
            if (word[i] < 65)
                return false;
            else if (word[i] > 90)
            {
                if (word[i] < 97 || word[i] > 122)
                    return false;
            }
        }

        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
            vowel = true;
        else if (word[i] >= 65 && word[i] <= 90)
            consonant = true;
        else if (word[i] >= 97 && word[i] <= 122)
            consonant = true;
    }
    if (vowel && consonant)
        return true;
    else
        return false;
}

int main()
{
}