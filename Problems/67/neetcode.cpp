#include <bits/stdc++.h>
using namespace std;

// this is definitely not a supposedly easy problem.
string addBinary(string a, string b) {
    string ans;
    int carry=0;

    // reverse a,b
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(int i=0; i<max(a.length(),b.length()); i++){
        int digitA= i<a.length() ? a[i]-'0' : 0;
        int digitB= i<b.length() ? b[i]-'0' : 0;
        
        int total=digitA+digitB+carry;
        string c=to_string(total%2);
        ans= c+ans;
        carry=total/2;

    }

    if(carry>0) ans="1"+ans;

    return ans;
}


int main(){
    
}