#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == ')')
            {
                // Pop characters until matching '(' is found
                string temp = "";
                while (!st.empty() && st.top() != '(')
                {
                    temp += st.top(); // Popping automatically reverses order
                    st.pop();
                }

                // Pop the '('
                if (!st.empty())
                {
                    st.pop();
                }

                // Push the reversed characters back onto the stack
                for (char ch : temp)
                {
                    st.push(ch);
                }
            }
            else
            {
                // Push characters and '(' onto the stack
                st.push(c);
            }
        }

        // Reconstruct the final result from the stack
        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        // Since elements were popped from a LIFO stack, reverse to restore original order
        reverse(result.begin(), result.end());

        return result;
    }
};