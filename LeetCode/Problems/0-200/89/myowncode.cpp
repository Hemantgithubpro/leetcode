#include <bits/stdc++.h>
using namespace std;

// code for leetcode problem 89
int decimaltobinary(int n){
    int binary = 0;
    int rem, i = 1;
    while(n!=0){
        rem = n%2;
        n = n/2;
        binary = binary + (rem*i);
        i = i*10;
    }
    return binary;
}

int binaryToGray(int num){
    return num ^ (num >> 1);
}

vector<int> grayCode(int n) {
    vector<int> ans;
    // for(int i=0; )
        
}

int main(){
    // cout<<binaryToGray(7)<<endl;
    // cout<<decimaltobinary(7)<<endl;
    // string str1="231";
    // int myint1=stoi(str1);
    // cout<<myint1;
    
    return 0;
}