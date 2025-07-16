#include <bits/stdc++.h>
using namespace std;

// to change bits from 1 to 0 in n only.
int minChanges(int n, int k) {
    int count=0;

    // n=13 -> 1101     k=4 ->  0100     count=2     n^k=1001
    // n=14 -> 1110     k=13->  1101     count=-1    n^k=0011
    // n=44 -> 101100   k=2->   000010

    int temp=n^k;
    // one more if statement can be: 
    // if(n&k != k) return -1;

    for(int i=0; i<32; i++){
        int ni=n&(1<<i);
        int ki=k&(1<<i);
        
        if(ni==0 & ki>0) return -1;
        if(temp&(1<<i)){
            count++;
        }
    }
    return count;
}

int main(){
    // cout<<minChanges(13,4);
    // cout<<minChanges(21,21);
    // cout<<minChanges(14,13);
    cout<<minChanges(44,2);
}