#include <bits/stdc++.h>
using namespace std;
// did it
int minMaxDifference(int num)
{
    string s = to_string(num);

    int mini = INT_MAX;
    int maxi = INT_MIN;

    // for minimum number: find most frequent no. or the front most
    // occurence int and make it '0' and positions don't change
    string s1 = s;
    int i = 0;
    char first = s1[0];
    while (s1[i] == '0' && i < s1.size() - 1)
    {
        i++;
        first = s1[i];
    }
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == first)
            s1[i] = '0';
    }
    mini = min(mini, stoi(s1));

    // for maximum number: find most frequent no. and make it '9' and
    // positions don't change
    string s2 = s;
    char f = s2[0];
    int j = 0;
    while (s2[j] == '9' && j < s2.size() - 1)
    {
        j++;
        f = s2[j];
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] == f)
            s2[i] = '9';
    }
    maxi = max(maxi, stoi(s2));

    return maxi - mini;
}

int main()
{
    // cout<<minMaxDifference(11891);
    cout << minMaxDifference(90);
}