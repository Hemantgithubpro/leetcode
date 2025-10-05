#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    // since its string, look ascii table a->97
    // ex. abcabcbb
    int l=0;
    int r=0;
    int len=0;
    int maxlen=0;
    
    // without unordered_map
    // // int hash[256]={-1};
    // vector<int> hash(256,-1);
    // while(r<s.size()){
    //     if(hash[s[r]]!=-1){ // its in hashset
    //         if(hash[s[r]]>=l){
    //             l=hash[s[r]]+1;
    //         }
    //     }
    //     hash[s[r]]=r;
    //     len=r-l+1;
    //     r++;
    //     maxlen=max(len,maxlen);
    // }
    // return maxlen;

    // with unordered_map
    unordered_map<char,int> mpp;
    
    for(int r=0; r<s.size(); r++){
        auto it=mpp.find(s[r]);
        if(it!=mpp.end()){  // if found
            if(it->second>=l) l=mpp[s[r]]+1;
        }
        mpp[s[r]]=r;
        len=r-l+1;
        maxlen=max(len,maxlen);
    }
    return maxlen;
}

int main(){
    string s="abcabcbb";
    cout<<lengthOfLongestSubstring(s);
    return 0;
}