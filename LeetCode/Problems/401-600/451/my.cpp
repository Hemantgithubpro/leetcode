#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> um;
    for (int i = 0; i < s.size(); i++)
    {
        char temp = s[i];
        um[temp]++;
    }

    vector<pair<char, int>> v;
    for (auto it = um.begin(); it != um.end(); it++)
    {
        
    }
}

int main()
{
}