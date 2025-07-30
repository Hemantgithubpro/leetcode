#include <bits/stdc++.h>
using namespace std;

int numDifferentIntegers(string word)
{
    unordered_set<string> us;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        int j = i;
        while (word[j] >= '0' && word[j] <= '9' && j < n)
        {
            temp += word[j];
            j++;
        }
        if (temp != "")
        {
            us.insert(temp);
            i = j;
        }
    }
    return us.size();
}

int main()
{
}