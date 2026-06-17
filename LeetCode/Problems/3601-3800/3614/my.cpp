#include <bits/stdc++.h>
using namespace std;

string givestr(string s)
{
    string res = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        // if s[i] is lowercase letter, append it to res
        if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25)
            res += s[i];
            else
        {
            if (s[i] == '#')
                res += res;
            else if (s[i] == '%')
                reverse(res.begin(), res.end());
                else if (s[i] == '*')
                res.size() > 0 ? res.erase(res.size() - 1, 1) : res = res;
        }
    }
    return res;
}
char processStr(string s, long long k)
{
    string g = givestr(s);
    
    if (g.size() <= k)
    return '.';
    else
    return g[k];
}

int main()
{
    // string s = "a#b%*";
    // cout << givestr(s)<<endl;
    // cout<<processStr(s,1)<<endl;
    
    //  s = "cd%#*#", k = 3
    cout<<processStr("cd%#*#",3)<<endl;

    // to conserve memory, i can just copy the last x characters to the first, and decrease k by x.
    // x can be 2^something < k.
    return 0;
}