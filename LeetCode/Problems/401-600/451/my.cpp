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
        v.emplace_back(it->first, it->second);
    }

    sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         {
             return a.second > b.second; // sort by frequency descending
         });

    string res;
    for (auto &p : v)
        res.append(p.second, p.first);
    return res;
}

int main()
{
    string s = "tree";
    cout << frequencySort(s);
}