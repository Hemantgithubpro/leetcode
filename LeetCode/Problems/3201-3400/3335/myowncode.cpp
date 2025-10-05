#include <bits/stdc++.h>
using namespace std;

int modulo(long long a){
    long long y=pow(10,9)+7;
    return a%y;
}

int lengthAfterTransformations(string s, int t)
{
    unordered_map<char,int> um;
    long long ans=s.size();
    for(int i=0; i<s.size(); i++){
        um[s[i]]++;
    }
    if(t<26){
        
    }
    else{

    }

}

int main()
{
    string s="";
    int t=4;
    cout<<lengthAfterTransformations(s,t);
}