#include<bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    int count=0;
    int temp=start^goal;
    for(int i=0; i<32; i++){
        if(temp&(1<<i)){
            count++;
        }
    }
    return count;
}

int main(){
    cout<<minBitFlips(34,54);
}