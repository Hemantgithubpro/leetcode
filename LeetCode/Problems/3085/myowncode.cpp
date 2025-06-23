#include <bits/stdc++.h>
using namespace std;

int minimumDeletions(string word, int k)
{
    unordered_map<char, int> um;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
        um[word[i]]++;
    }
    // now i've the frequency of every character of 'word'

    int todelete = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(um[word[i]] - um[word[j]]) > k)
                todelete++;
        }
    }

    return todelete / 2;
}

int main()
{
    string word = "aabcaba";
    int k = 0;
    cout << minimumDeletions(word, k);
    return 0;
}