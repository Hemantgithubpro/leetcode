#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            // if s[i] is lowercase letter, append it to res
            if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25)
                res += s[i];
            else {
                if (s[i] == '#')
                    res += res;
                else if (s[i] == '%')
                    reverse(res.begin(), res.end());
                else if (s[i] == '*')
                    res.size() > 0 ? res.erase(res.size()-1,1) : res = res;
            }
        }
        return res;
    }
};

int main()
{
    char a='b';
    cout<< a-'a';
    return 0;
}