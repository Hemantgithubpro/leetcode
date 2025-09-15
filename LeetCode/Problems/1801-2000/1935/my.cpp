#include <bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string brokenLetters)
{
    int i = 0;
    vector<string> v;
    string temp = "";
    while (i < text.size())
    {
        if (text[i] != ' ')
        {
            temp += text[i];
        }
        else
        {
            // if (temp != "")
            v.push_back(temp);
            temp = "";
        }
        if (i == text.size() - 1)
        {
            v.push_back(temp);
            break;
        }
        i++;
    }
    unordered_set<char> us;
    for (int i = 0; i < brokenLetters.size(); i++)
    {
        us.insert(brokenLetters[i]);
    }
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        string s = v[i];
        bool a = true;
        for (int j = 0; j < s.size(); j++)
        {
            char temp = s[j];
            if (us.find(temp) != us.end())
                a = false;
        }
        if (a)
            count++;
    }
    return count;
}

int main()
{
    string text = "hello world";
    string brokenLetters = "ad";
    canBeTypedWords(text, brokenLetters);
}