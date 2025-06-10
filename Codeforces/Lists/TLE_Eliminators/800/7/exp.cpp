#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // code
}

bool isin(string x, string s)
{
    int j = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == s[j])
        {
            j++;
            if (j >= s.size())
                return true;
        }
        else
        {
            if (x[i] == s[0])
            {
                j = 1;
            }
            else
            {
                j = 0;
            }
        }
    }
    return false;
}

int main()
{
    // string s="abc";
    // cout<<s<<endl;
    // s.push_back('d');
    // string x="efgh";
    // for (int i = 0; i < x.size(); i++)
    // {
    //     s.push_back(x[i]);
    // }

    // cout<<s<<endl;

    // string p="abcddefgh";
    // if(s==p) cout<<1;
    // else cout<<9;

    string s = "abc";
    string x = "dsabc";
    cout << isin(x, s);

    return 0;
}
