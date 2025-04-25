#include <bits/stdc++.h>
using namespace std;
int main(){
    int x=52;
    string xk=to_string(x);
    xk.append("5252");
    cout<<xk;
    long long st=stoll(xk);
    cout<<endl<<st+1;
}