#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    // a = "11", b = "1"
    // Output: "100"

    // wrong method
    // stack<char> ans;
    // int l=max(a.length(),b.length());
    // for(int i=l-1; i>=0; i--){
    //     if(a[i]=='1' && b[i]=='1') ans.push('0');
    //     else if(a[i]=='1' && b[i]=='0') ans.push('1');
    //     else if(a[i]=='0' && b[i]=='1') ans.push('1');
    //     else if(a[i]=='0' && b[i]=='0') ans.push('0');
    // }

    // string a;
    // int j=0;
    // while(!ans.empty()){
    //     a[j++]=ans.top();
    //     ans.pop();
    // }
    // return a;




    
    
    // brute force : convert p,q to decimal , then add them.
    int p=stoi(a);
    int q=stoi(b);

    // optimal approach: do some bitwise operation with p,q such that they add themselves.
    // 11
    // 01
    // xor
    for(int i=0; i<32; i++){
        int x=a[i]-48;
        int y=b[i]-48;
    }
}

int main(){
    string x="101";
    cout<<x<<endl;
    cout<<stoi(x);
}