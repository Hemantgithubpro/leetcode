#include <bits/stdc++.h>
using namespace std;

int maxContainers(int n, int w, int maxWeight) {
    int ans;
    ans=maxWeight/w;
    if(ans>n*n) return n*n;
    else return ans;
}

int main(){
    
}