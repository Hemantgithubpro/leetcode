#include <bits/stdc++.h>
using namespace std;

string smallestNumber(string pattern)
{ // optimal approach
    string ans = "";
    stack<int> st;
    int count = 1;
    int n=pattern.size();
    for (int i = 0; i <=n ; i++)
    {
        st.push(count);
        count++;
        if (i==n || pattern[i] == 'I')
        {
            while (!st.empty())
            {
                int temp = st.top();
                ans += temp + '0';
                st.pop();
            }
        }
    }
    return ans;
}

int main()
{
    string pattern = "IIIDIDDD";
    cout << smallestNumber(pattern);
}