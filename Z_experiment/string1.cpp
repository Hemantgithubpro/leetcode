#include <bits/stdc++.h>
using namespace std;

void printStr(string &a){
    for(int i=0; i<a.length(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    string a="qrst";
    printStr(a);
    // a=a+"p"; // q r s t p
    // a="p"+a; // p q r s t
    printStr(a);
}