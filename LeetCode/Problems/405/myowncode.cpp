#include <bits/stdc++.h>
using namespace std;

string toHex(int num) { // too complex
    // one case when, num>9, we make A,B,C,D,E,F
    string ans;
    while(num>0){
        int carry=0;
        // if(num%16>10) ans=(num%16)+40+ans;
        if(num%16>10){
            if(num%16==10) ans='A'+ans;
            else if(num%16==11) ans='B'+ans;
            else if(num%16==12) ans='C'+ans;
            else if(num%16==13) ans='D'+ans;
            else if(num%16==14) ans='E'+ans;
            else if(num%16==15) ans='F'+ans;
        }
        else ans = to_string(num % 16) + ans;
        num /= 16;
    }
    return ans;
}

int main(){
    string a=toHex(15);
    cout<<a[0]<<endl;
    // <<a[1];
}