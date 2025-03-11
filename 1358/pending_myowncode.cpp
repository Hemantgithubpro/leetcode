#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int count=0;
    int i=0;
    int j=s.size()-1;
    while(j<i){
        unordered_set<int> us;
        for(int k=i; k<j; k++){
            auto it=us.find(s[k]);
            if(it!=us.end()){
                
            }
            else us.insert(s[k]);    
        }
    }
}

int main(){
    string str="abcbcca";
    cout<<numberOfSubstrings(str);
}