#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    // since its string, look ascii table a->97
    // ex. abcabcbb
    
    // without unordered_map
    int l=0;
    int r=0;
    int len=0;
    int maxlen=0;
    // int hash[256]={-1};
    vector<int> hash(256,-1);
    while(r<s.size()){
        if(hash[s[r]]!=-1){ // its in hashset
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
        }
        hash[s[r]]=r;
        len=r-l+1;
        r++;
        maxlen=max(len,maxlen);
    }
    return maxlen;
}
    // unordered_map<char,int> mpp;
    // for(int i=0; i<s.size(); i++){
    //     auto it=mpp.find(s[i]);
    //     if(it==mpp.end()){
    //         mpp[s[i]]=i;
    //     }
    // }

int main(){
    string s="abcabcbb";
    cout<<lengthOfLongestSubstring(s);
    return 0;
}