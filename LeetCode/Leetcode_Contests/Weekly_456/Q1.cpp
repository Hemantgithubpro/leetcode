#include <bits/stdc++.h>
using namespace std;

vector<string> partitionString(string s)
{
    unordered_set<string> us;
    vector<string> ans;
    // string temp(1, s[0]);
    string temp="";
    // us.insert(temp);
    for (int i = 0; i < s.size() ; i++)
    {
        if (us.find(temp) != us.end())
        {
            // found
            temp += s[i];
        }
        else
        {
            // not found
            us.insert(temp);
            ans.push_back(temp);
            temp = s[i];
        }
    }
    return ans;
}

int main()
{
    string s = "abbccccd";
    vector<string> ans = partitionString(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}