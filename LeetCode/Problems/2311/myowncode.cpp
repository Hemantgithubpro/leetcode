#include <bits/stdc++.h>
using namespace std;

int binarytodecimal(string&s){
    int ans=0;
    int power=0;
    for(int i=s.size()-1; i>=0; i--){
        int temp=s[i] - '0';
        ans+=pow(2,power)*temp;
        power++;
    }
    return ans;
}

int main(){
    
}