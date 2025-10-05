// built-in function to count set bits (1's) in binary representation
int __builtin_popcount(unsigned int x);
#include <bits/stdc++.h>
using namespace std;

// brute force, ig it'll give tle
// yup, it gave tle, i'll have solve it in log n or less time complexity
char kthCharacter(int k, vector<int> &operations)
{
    string s = "a";

    for (int i = 0; i < operations.size() && s.size() < k; i++)
    {
        string temp = s;
        // if ops[i]==0
        if (operations[i] == 0)
        {
            s += s;
        }
        else
        {
            // if ops[i]==1
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != 'z')
                {
                    temp += s[i] + 1;
                }
                else
                {
                    temp += 'a';
                }
            }
            s = temp;
        }
    }

    return s[k - 1];
}

int main()
{
    int k = 10;
    vector<int> ops = {0, 1, 0, 1};
    cout << kthCharacter(k, ops);
}