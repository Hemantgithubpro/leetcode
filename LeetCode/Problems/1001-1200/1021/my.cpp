#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string arr = "";
    unordered_set<int> v;
    string removeOuterParentheses(string s)
    {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            st.push(s[i]);
            if (s[i] == '(')
                ;
            else
            {
                st.pop();
                st.pop();
            }
            if (st.empty())
                v.insert(i);
        }
        for (int i = 1; i < n; i++)
        {
            if (v.count(i))
                i++;
            else
                arr += s[i];
        }
        return arr;
    }
};

int main()
{
}