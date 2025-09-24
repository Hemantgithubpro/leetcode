#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compare(string &s1, string &s2)
    {
        int a = stoi(s1);
        int b = stoi(s2);
        if (a > b)
            return 1;
        else if (a < b)
            return -1;
        else
            return 0;
    }
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0;
        string s1 = "", s2 = "";
        while (i < version1.size() && j < version2.size())
        {
            if(version1[i]!='.') s1+=
        }
    }
};

int main()
{
}