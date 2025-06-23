#include <bits/stdc++.h>
using namespace std;
string rle(string a)
{
    // rle is [frequency,number]
    unordered_map<char, int> um;
    for (int i = 0; i < a.size(); i++)
    {
        um[a[i]]++;
    }
    string ans = "";
    // for (auto it = um.begin(); it != um.end(); it++)
    // {
    //     string temp = to_string(it->second);
    //     ans += temp + it->first;
    // }
    // for (int i = 0; i < a.size(); i++)
    // {
        
    // }
    
    return ans;
}

string countAndSay(int n)
{
    // recursion will be there
    if(n==1) return "1";
    return rle(countAndSay(n-1));
}

int main()
{
    int n = 3;
    // cout << countAndSay(n) << endl;
    cout<<rle("21");
    return 0;
}
