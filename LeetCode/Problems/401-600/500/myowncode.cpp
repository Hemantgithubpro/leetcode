#include <bits/stdc++.h>
using namespace std;
// ascii: a=97 A=65
bool isin(string s)
{
    string first = "qwertyuiop";
    unordered_set<char> us;
    for (int i = 0; i < first.size(); i++)
    {
        us.insert(first[i]);
        us.insert(first[i]-32);
    }
    
    string second = "asdfghjkl";
    unordered_set<char> us2;
    for (int i = 0; i < second.size(); i++)
    {
        us2.insert(second[i]);
        us2.insert(second[i]-32);
    }
    string third = "zxcvbnm";
    unordered_set<char> us3;
    for (int i = 0; i < third.size(); i++)
    {
        us3.insert(third[i]);
        us3.insert(third[i]-32);
    }
    
    //first letter is in 
    if(us.find(s[0])!=us.end()){
        for (int i = 1; i < s.size(); i++)
        {
            if(us.find(s[i])==us.end()) return false;
        }
    }
    else if(us2.find(s[0])!=us.end()){
        for (int i = 1; i < s.size(); i++)
        {
            if(us2.find(s[i])==us2.end()) return false;
        }
        
    }
    else{
        for (int i = 1; i < s.size(); i++)
        {
            if(us3.find(s[i])==us3.end()) return false;
        }
    }
    return true;
    
}

vector<string> findWords(vector<string> &words)
{
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
        if (isin(words[i]))
            ans.push_back(words[i]);
    }
    return ans;
}

int main()
{
    vector<string> words={"Hello","Alaska","Dad","Peace"};
}