#include <bits/stdc++.h>
using namespace std;

int modulo(long long a){
    long long y=pow(10,9)+7;
    return a%y;
}

// i will try to directly do operations on the string itself.
int lengthAfterTransformations(string s, int t)
{
    unordered_map<char,int> um;
    long long ans=s.size();
    for(int i=0; i<s.size(); i++){
        um[s[i]]++;
    }
    for(int i=0; i<s.size(); i++){
        int a='z'-s[i];
        if(a < t);
        else ans++;
    }
    return modulo(ans);
}

int main()
{
    string s="abcxyz";
    int t=3;
    cout<<lengthAfterTransformations(s,t);
}