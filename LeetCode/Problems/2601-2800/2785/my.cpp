#include <bits/stdc++.h>
using namespace std;

// not optimal solution, but correct solution
string sortVowels(string s)
{
    unordered_set<char> us = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    int n = s.size();
    string t(n, '.');
    vector<char> v;
    for (int i = 0; i < n; i++)
    {
        char temp = s[i];
        // if(us.find(temp)!=us.end()){
        if (us.count(temp))
        {
            v.push_back(temp);
        }
        else
            t[i] = s[i];
    }
    sort(v.begin(), v.end());
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == '.')
        {
            t[i] = v[j];
            j++;
        }
    }
    return t;
}

int main()
{
    string s = "lEetcOde";
    cout << sortVowels(s);
}