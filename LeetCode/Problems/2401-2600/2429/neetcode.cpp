#include <bits/stdc++.h>
using namespace std;

int count_bits(int n){
    int res=0;
    while(n>0){
        res+=1&n;
        n=n>>1;
    } 
    return res;
}

int minimizeXor(int num1, int num2) {
    int count1=count_bits(num1);
    int count2=count_bits(num2);
    int x=num1;

    int i=0;
    // remove least significant bit
        while(count1>count2){
            if(x&(1<<i)) {
                count1--;
                x=x^(1<<i);
            }
            i++;
        }

    // adding leas significant bit
    while(count1<count2){
        if((x&(1<<i))==0) {
            count1++;
            x=x|(1<<i);
        }
        i++;
    }
    return x;
}

int main(){
    
}