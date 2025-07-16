#include <bits/stdc++.h>
using namespace std;

// size at least k, so i have to negate the condition of size lower than k.
int possibleStringCount(string word, int k)
{
    const int MOD = 1e9+7;

    int ans = 1;
    for (int i = 0; i < word.size() - 1; i++)
    {
        int j = i;
        int temp = 0;
        while (word[j] == word[j + 1])
        {
            temp++;
            j++;
        }
        ans += temp;
        i = j;
    }
    return ans;
}

int main()
{
    string word = "aabbccdd";
    int k = 7;
    cout << possibleStringCount(word, k);
    return 0;
}