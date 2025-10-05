#include <bits/stdc++.h>
using namespace std;

// this was not the optimal soln. i can find a better soln later on.
// TC: O(n) where n is the length of str1
// SC: O(1) as we are not using any extra space.
bool canMakeSubsequence(string str1, string str2) {
    int i=0;
    int j=0;
    while(i<str1.size()){
        if(str1[i]==str2[j] || (str1[i]+1)==str2[j]){
            j++;
        }    
        else if(str1[i]=='z' && str2[j]=='a'){
            j++;
        }    
        if(j>=str2.size()) return true;
        i++;
    }    
    return false;
}    



int main(){
    string str1, str2;
    str1="abcde";
    str2="ace";
    cout<<canMakeSubsequence(str1,str2)<<endl;
    return 0;
}