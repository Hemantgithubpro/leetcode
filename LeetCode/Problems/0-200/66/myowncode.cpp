#include<bits/stdc++.h>
using namespace std;

bool alldigits9(vector<int>& digits){
    for(int i=0; i<digits.size(); i++){
        if(digits[i]!=9) return false;
    }
    return true;
}

vector<int> plusOne(vector<int>& digits) {
    int lastindex=digits.size()-1;
    if(digits[digits.size()-1]!=9) digits[digits.size()-1]++;
    else if(digits.size()==1){
        digits[0]=1;
        digits.push_back(0);
    }
    else if(alldigits9(digits)){
        digits[0]=1;
        for(int i=1; i<digits.size(); i++){
            digits[i]=0;
        }
        digits.push_back(0);
    }
    else{
        digits[lastindex]=0;
        digits[lastindex-1]++;
        for(int i=digits.size()-1; i>0; i--){
            if(digits[i]==10){
                digits[i]=0;
                digits[i-1]+=1;
            }
        }
    }
    return digits;
}

int main(){
    // mainly testcases below:
    // 9 9 9 9
    // 2 3 4 1
    // 4 5 2 9
    
}