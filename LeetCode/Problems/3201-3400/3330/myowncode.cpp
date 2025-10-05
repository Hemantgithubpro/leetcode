#include <bits/stdc++.h>
using namespace std;

int possibleStringCount(string word)
{
    // unordered_map<char, int> um;
    // int ans=1;
    // for(int i=0; i<word.size(); i++){
    //     um[word[i]]++;
    // }
    // for(auto it=um.begin(); it!=um.end(); it++){
    //     if(it->second>1) ans+=it->second-1;
    // }

    int ans = 1;
    for (int i = 0; i < word.size() - 1; i++)
    {
        int j = i;
        int temp = 0;
        while (word[j] == word[j + 1])
        {
            temp++;
            j++;
        }
        ans += temp;
        i = j;
    }
    return ans;
}