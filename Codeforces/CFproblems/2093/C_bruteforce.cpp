#include <bits/stdc++.h>
using namespace std;

bool isprime(long long a){
    if(a <= 1) return false;
    if(a <= 3) return true;
    if(a % 2 == 0 || a % 3 == 0) return false;
    
    // Only check up to square root of a
    for(long long i = 5; i * i <= a; i += 6){
        if(a % i == 0 || a % (i + 2) == 0) return false;
    }
    return true;
}

int lenx(int x){
    int ans=0;
    while(x>0){
        ans++;
        x=x/10;
    }
    return ans;
}

string solve(int x, int k){
    // Check if number can be prime based on divisibility rules
    if(k > 1 && x % 2 == 0) return "NO"; // Even concatenation can't be prime when k > 1
    if(k > 1 && x % 5 == 0) return "NO"; // Multiple of 5 concatenation can't be prime when k > 1
    
    long long s = x;
    int lenofx = lenx(x);
    long long mul = pow(10, lenofx);
    
    // Safely build the concatenated number
    for(int i = 0; i < k-1 && s <= 1e18; i++){
        s = s * mul + x;
    }
    
    // Handle potential overflow
    if(s <= 0 || s > 1e18) {
        return "NO"; // Numbers beyond 10^18 are unlikely to be prime and checking would be too slow
    }
    
    if(isprime(s)) return "YES";
    return "NO";
}

int main(){
    int testcases;
    cin>>testcases;
    for(int i=0; i<testcases; i++){
        int x;
        cin>>x;
        int k;
        cin>>k;
        cout<<solve(x,k)<<endl;
    }
}