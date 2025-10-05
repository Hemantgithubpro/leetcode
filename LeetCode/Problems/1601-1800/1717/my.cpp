#include <bits/stdc++.h>
using namespace std;

// int maximumGain(string s, int x, int y)
// {
//     // ig dp
//     // but lets try counting ab and ba
//     int noofab = 0, noofba = 0;
//     for (int i = 0; i < s.size() - 1; i++)
//     {
//         if (s[i] == 'a' && s[i + 1] == 'b')
//             noofab++;
//         else if (s[i] == 'b' && s[i + 1] == 'a')
//             noofba++;
//     }
//     int maxi = 0;
//     // whatever is larger x or y, remove according to that
//     if (x >= y)
//     {
//         maxi += (noofab * x);
//         noofab = 0, noofba = 0;
//         for (int i = 0; i < s.size() - 1; i++)
//         {
//             if (s[i] == 'a' && s[i + 1] == 'b')
//             {
//                 s[i] = '.';
//                 s[i + 1] = '.';
//             }
//         }
//         string sn = "";
//         int it = 0;
//         while (it < s.size())
//         {
//             if (s[it] != '.')
//                 sn += s[it];
//             it++;
//         }

//         // now check ba in sn
//         for (int i = 0; i < sn.size() - 1; i++)
//         {
//             if (sn[i] == 'b' && sn[i + 1] == 'a')
//                 noofba++;
//         }
//         maxi += (noofba * y);
//     }
//     else
//     {
//         maxi += (noofba * y);
//         noofab = 0, noofba = 0;
//         for (int i = 0; i < s.size() - 1; i++)
//         {
//             if (s[i] == 'b' && s[i + 1] == 'a')
//             {
//                 s[i] = '.';
//                 s[i + 1] = '.';
//             }
//         }
//         string sn = "";
//         int it = 0;
//         while (it < s.size())
//         {
//             if (s[it] != '.')
//                 sn += s[it];
//             it++;
//         }

//         // now check ba in sn
//         for (int i = 0; i < sn.size() - 1; i++)
//         {
//             if (sn[i] == 'a' && sn[i + 1] == 'b')
//                 noofab++;
//         }
//         maxi += (noofab * x);
//     }

//     return maxi;
// }

int maximumGain(string s, int x, int y)
{
    int n=s.size();
    // one more method from stack, understood from solution, writing myself
    int maxi = max(x, y);
    if (x > y)
    { // we'll find 'ab' first
        int ans=0;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if(st.top()=='a'&&s[i]=='b'){
                ans+=x;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        stack<char> st2; // for 'ba'
        for (int i = 0; i < s.size(); i++)
        {
            
        }
        
        
    }
    else
    { // we'll find 'ba' first
    }
}

int main()
{
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    cout << maximumGain(s, x, y);
    return 0;
}