#include <bits/stdc++.h>
using namespace std;

// brute force soln
string lexSmallest(string s)
{
    int n = s.length();
    string result = s;
    
    // Try reversing first k characters (k from 1 to n)
    for (int k = 1; k <= n; k++)
    {
        string temp = s;
        reverse(temp.begin(), temp.begin() + k);
        if (temp < result)
        {
            result = temp;
        }
    }
    
    // Try reversing last k characters (k from 1 to n)
    for (int k = 1; k <= n; k++)
    {
        string temp = s;
        reverse(temp.end() - k, temp.end());
        if (temp < result)
        {
            result = temp;
        }
    }
    
    return result;
}

int main()
{
    // Test cases
    string s1 = "abcd";
    cout << lexSmallest(s1) << endl; // Expected: "abcd"
    
    string s2 = "dcba";
    cout << lexSmallest(s2) << endl; // Expected: "abcd"
    
    string s3 = "acdb";
    cout << lexSmallest(s3) << endl; // Expected: "abdc"
    
    return 0;
}