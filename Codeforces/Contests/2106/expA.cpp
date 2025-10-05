#include <bits/stdc++.h>
using namespace std;

int findnoof1(int num, int digits){
    int noof1=0;
    for(int j=0; j<digits; j++){
        if(num%2){
            noof1++;
            num/=10;
        }
        else num/=10;
    }
    return noof1;
}


int main(){
    int num=1010;
    int digit=6;
    cout<<findnoof1(num,digit);
}