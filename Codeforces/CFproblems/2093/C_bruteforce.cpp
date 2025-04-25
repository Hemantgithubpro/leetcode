#include <bits/stdc++.h>
using namespace std;

bool isprime(long long& a){
    for(int i=2; i<a; i++){
        if((a%i)==0) return false;
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
    long long s=x;
    int lenofx=lenx(x);
    int mul=pow(10,lenofx);
    for(int i=0; i<k-1; i++){
        s=s*mul+x;
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