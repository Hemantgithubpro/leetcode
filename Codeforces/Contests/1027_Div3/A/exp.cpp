#include <bits/stdc++.h>
using namespace std;



int main(){
    string s="2026";
    long long x=stoi(s);

    double a = sqrt(x);
    if(a - floor(a) == 0){
        cout << "Perfect square" << endl;
    } else {
        cout << "Not a perfect square" << endl;
    }

    while(a>1){
        a=a/10;
    }
    cout<<a;

}