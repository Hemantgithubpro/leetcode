#include <bits/stdc++.h>
using namespace std;


int finddigits(int n)
{
    int a = 0;
    while (n){
        a++;
        n=n/10;
    }
    return a;
}

int main(){
    int n=23541;
    cout<<finddigits(n);
}