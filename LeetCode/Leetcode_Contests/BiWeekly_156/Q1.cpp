#include <bits/stdc++.h>
using namespace std;

int maxFreqSum(string s)
{
    unordered_map<char, int> mpp;
    for(int i=0; i<s.length(); i++){
        mpp[s[i]]++;
    }
    
    int vowel=0;
    int conson=0;
    for(auto it=mpp.begin(); it!=mpp.end(); it++){
        if(it->first=='a'|| it->first=='e'|| it->first=='i'|| it->first=='o'|| it->first=='u'){
            vowel=max(vowel,it->second);
        }
        else{
            conson=max(conson,it->second);
        }
    }
    // cout<<vowel<<endl<<conson<<endl;
    return vowel+conson;
}


int main()
{
    string str="successes";
    cout<<maxFreqSum(str);
}