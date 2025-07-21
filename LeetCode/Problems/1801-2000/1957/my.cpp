#include <bits/stdc++.h>
using namespace std;

string makeFancyString(string s)
{
    // int cnt = 0;
    // for (int i = 0; i < s.size() - 2; i++)
    // {
    //     if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
    //         cnt++;
    // }
    if (s.size() < 3)
        return s;
    string st = "";
    st += s[0];
    st += s[1];
    for (int i = 2; i < s.size(); i++)
    {
        if (st[st.size() - 1] == st[st.size() - 2] && st[st.size() - 1] == s[i])
            continue;
        else
            st += s[i];
    }
    return st;
}

int main()
{
    string s = "aabbaaaa";
    string ans = makeFancyString(s);
    cout << ans;
}