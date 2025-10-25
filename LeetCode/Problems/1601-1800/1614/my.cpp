#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{
    int ans = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        int si = st.size();
        ans = max(ans, si);
        if (s[i] == ')')
            st.pop();
    }
    return ans;
}

int main()
{
}