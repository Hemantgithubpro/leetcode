#include <bits/stdc++.h>
using namespace std;

// could've optimised it more, but this is good enough for now
string greatestLetter(string s)
{
    string ans = "";
    unordered_set<int> us;
    for (int i = 0; i < s.size(); i++)
    {
        us.insert(s[i]);
    }
    unordered_set<int> cap;
    for (int i = 0; i < s.size(); i++)
    {
        auto it1 = us.find(s[i] + 32);
        if (it1 != us.end())
        {
            if (s[i] < 97)
                cap.insert(s[i]);
            else
                cap.insert(s[i] - 32);
        }
    }
    int a = 64;
    for (auto it = cap.begin(); it != cap.end(); it++)
    {
        int temp = *it;
        if (temp >= a)
            a = temp;
    }

    if (a != 64)
        ans += char(a);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    greatestLetter(s);
    // cout<<greatestLetter(s)<<endl;
    return 0;
}