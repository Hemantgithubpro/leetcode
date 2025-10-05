#include <bits/stdc++.h>
using namespace std;

// logic: we'll use long instead of int bcoz of 2^31


int divide(int dividend, int divisor) {
    // long n=abs(dividend);
    // long d=abs(divisor);

    long long n=abs((long long)dividend);
    long long d=abs((long long)divisor);


    bool sign=true;
    if(dividend>=0 && divisor<0) sign=false;
    if(divisor>=0 && dividend<0) sign=false;

    if(dividend==divisor) return 1;
    if(divisor==1) return dividend;
    
    long ans=0;
    while(n>=d){
        int count=0;
        // while(n>=(d<<count)) count++; // did  a mistake here of missing out +1 with count.
        while(n>=(d<<count+1)) count++;
        ans+=1<<count;
        n-=d<<count;
    }

    // a few edge cases
    if(ans>=INT_MAX && sign==true) return INT_MAX;
    if(ans>=INT_MAX && sign==false) return INT_MIN;

    return sign ? ans : (-1*ans);

}

int main(){
    cout<<divide(22,7);
}