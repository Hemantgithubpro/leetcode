#include <bits/stdc++.h>
using namespace std;

string majorityFrequencyGroup(string s)
{
    map<char, int> mpp;
    for (char it : s)
        mpp[it]++;

    map<int, vector<char>> mp2;
    for (auto it : mpp)
    {
        if (mp2.count(it.second))
        {
            vector<char> v = mp2[it.second];
            v.push_back(it.first);
            mp2[it.second] = v;
        }
        else
            mp2[it.second] = {it.first};
    }

    int freq = -1;
    string ans = "";
    for (auto it : mp2)
    {
        if ((it.second.size() == ans.size()) && (it.first > freq))
        {
            freq = it.first;
            string s = "";
            for (auto i : it.second)
                s += i;

            ans = s;
        }
        else if (it.second.size() > ans.size())
        {
            freq = it.first;
            string s = "";
            for (auto i : it.second)
                s += i;

            ans = s;
        }
    }
    return ans;
}
