// not the intended two pointers, but did it with stack
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // string reverse(string s){
    //     int n = s.size();
    //     for(int i=0; i<n/2;i++){
    //         char temp;
    //         temp=s[i];
    //         s[i]=s[n-i-1];
    //         s[n-i-1]=temp;
    //     }
    //     return s;
    // }

    // string rev_space(string s){
    //     int i=0;
    //     while(s[i]!='\0'){
    //         i++;
    //         int j=0;
    //         while(s[j]==' '){
    //             j++;
    //         }
    //         int k=0;
    //         while(s[k+j]!=' '){
    //             k++;
    //         }

    //     }
    // }

    // using stack

    string reverseWords(string s)
    {
        // reverse(s);
        stack<string> st;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                temp += s[i];
            else
            {
                if (temp != "")
                    st.push(temp);
                temp = "";
            }
            if (i == s.size() - 1)
            {
                if (temp != "")
                    st.push(temp);
            }
        }
        string ans = "";
        while (!st.empty())
        {
            string temp = st.top();
            ans += temp;
            if (st.size() > 1)
                ans += " ";
            st.pop();
        }
        return ans;
    }
};
int main()
{
}